#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class EnviarSinal(Node):
    def __init__(self):
        super().__init__('enviar_sinal')
        self.publisher_ = self.create_publisher(String, 'round', 10)
        self.timer = self.create_timer(1, self.publish_message)
        # self._counter = 0
        # self.create_timer(0.5,self.timer_callback)

    def publish_message(self):
        msg = String()
        msg.data = 'round180'
        self.publisher_.publish(msg)
        self.get_logger().info('Publicando: "round180"')

def main(args=None):
    rclpy.init(args=args)
    node = EnviarSinal()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()


