#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from geometry_msgs.msg import Twist

class FinishRound(Node):
    def __init__(self):
        super().__init__('finish_round')
        self.subscription = self.create_subscription(Twist, 'cmd_vel', self.listener_callback, 10)
        self.publisher_ = self.create_publisher(String, 'rotatetopicpy', 10)

    def listener_callback(self, msg):
        if msg.angular.z == 0.0:  # Verifica se a rotação parou
            self.get_logger().info('Rotação finalizada')
            final_msg = String()
            final_msg.data = 'finalizado'
            self.publisher_.publish(final_msg)

def main(args=None):
    rclpy.init(args=args)
    node = FinishRound()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
