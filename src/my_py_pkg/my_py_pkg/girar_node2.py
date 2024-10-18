import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import String

class VelocityPublisher(Node):
    def __init__(self):
        super().__init__('rotate')

        #Cria o pub
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)

        #sub para o topico round
        self.subscription = self.create_subscription(String, 'round', self.listener_callback, 10)

        #taxa de publicacao 10hz
        self.timer_period = 0.1
        #timer recebe round
        self.timer = None

        #Msg Twist pra controlar vel
        self.velocity_msg = Twist()
        self.velocity_msg.linear.x = 0.0    #vel linear x
        self.velocity_msg.linear.y = 0.0
        self.velocity_msg.linear.z = 0.0
        self.velocity_msg.angular.x = 0.0
        self.velocity_msg.angular.y = 0.0
        self.velocity_msg.angular.z = 0.0

        #tempo decorrido em s
        self.elapsed_time = 0.0
        #duração da ação
        self.duration = 1.0

    def listener_callback(self, msg):
        if msg.data == 'round180':
            self.get_logger().info('Recebido comando "round180"')
            #Configura a vel ang para girar
            self.velocity_msg.angular.z = 1.0
            #Criar um timer para pub a vel
            self.timer = self.create_timer(self.timer_period, self.publsh_velocity)

    def publish_velocity(self):
        if self.elapsed_time < self.duration:

            self.publisher_.publish(self.velocity_msg)
            self.get_logger().info('Publicando: linear.x: %.2f' % (self.velocity_msg.linear.x))
            self.get_logger().info('Publicando: linear.y: %.2f' % (self.velocity_msg.linear.y))
            self.get_logger().info('Publicando: linear.z: %.2f' % (self.velocity_msg.linear.z))

            self.get_logger().info('Publicando: angular.x: %.2f' % (self.velocity_msg.angular.x))
            self.get_logger().info('Publicando: angular.y: %.2f' % (self.velocity_msg.angular.y))
            self.get_logger().info('Publicando: angular.z: %.2f' % (self.velocity_msg.angular.z))
            self.get_logger().info(' ')

            self.elapsed_time += self.timer_period
        else:

            # Para o robô
            self.velocity_msg.linear.x = 0.0
            self.velocity_msg.linear.y = 0.0
            self.velocity_msg.linear.z = 0.0

            self.velocity_msg.angular.x = 0.0
            self.velocity_msg.angular.y = 0.0
            self.velocity_msg.angular.z = 0.0

            self.publisher_.publish(self.velocity_msg)
