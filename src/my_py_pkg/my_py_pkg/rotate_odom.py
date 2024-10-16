import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from geometry_msgs.msg import Quaternion

class RotateRobot(Node):
    def __init__(self):
        super().__init__('rotate_robot')
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        self.subscription = self.create_subscription(
            Odometry,
            '/odom',
            self.listener_callback,
            10
        )
        self.target_angle = 3.14  # 180 graus em radianos
        self.current_angle = 0.0
        self.rotating = False

    def listener_callback(self, msg):
        # Atualiza o ângulo atual do robô com base na mensagem de odometria
        # self.current_angle = msg.pose.pose.orientation.z  
        self.current_angle = self.

        if self.rotating:
            if abs(self.current_angle - self.target_angle) < 0.1:  # Margem de erro
                self.rotating = False
                twist = Twist()
                self.publisher_.publish(twist)
                self.get_logger().info('Rotação concluída!')

    def rotate(self):
        self.rotating = True
        twist = Twist()
        twist.angular.z = 1.0  # Velocidade angular (ajuste conforme necessário)
        self.publisher_.publish(twist)

def main(args=None):
    rclpy.init(args=args)
    rotate_robot = RotateRobot()
    rotate_robot.rotate()
    rclpy.spin(rotate_robot)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
