#!/usr/bin/env python3
import rclpy  # Permite usar ROS2 em Python
from rclpy.node import Node  # permite criar instâncias da classe Node
from geometry_msgs.msg import Twist
from std_msgs.msg import String 

class VelocityPublisher(Node):
    def __init__(self):
        super().__init__('rotate')

        # Cria o publisher no tópico /cmd_vel
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        
        #subscriber para escutar o topico rotatetopicpy
        self.subscription = self.create_subscription(String, 'rotatetopicpy', self.listener_callback, 10)

        # Define a taxa de publicação (por exemplo, 10 Hz)
        self.timer_period = 0.1  # Segundos (10 Hz)
        self.timer = None  # O timer só será criado quando receber o "round180"

        # Cria uma mensagem Twist para controlar a velocidade
        self.velocity_msg = Twist()
        self.velocity_msg.linear.x = 0.0  # Velocidade linear no eixo X (frente)
        self.velocity_msg.linear.y = 0.0
        self.velocity_msg.linear.z = 0.0
        self.velocity_msg.angular.x = 0.0
        self.velocity_msg.angular.y = 0.0
        self.velocity_msg.angular.z = 0.0
        
        self.elapsed_time = 0.0  # Tempo decorrido em segundos
        self.duration = 1.0  # Duração em segundos para ir para frente

    
    def listener_callback(self, msg):
        if msg.data == 'round180':
            self.get_logger().info('Recebido comando "round180"')
            # Configura a velocidade angular para girar
            self.velocity_msg.angular.z = 1.0

            # Cria um timer para começar a publicar a velocidade
            self.timer = self.create_timer(self.timer_period, self.publish_velocity)

    def publish_velocity(self):
        if self.elapsed_time < self.duration:
            # Publica a mensagem Twist no tópico /cmd_vel
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

            self.publisher_.publish(self.velocity_msg)  # Publica a parada
            self.get_logger().info('Parando o robô.')
            self.timer.cancel()  # Para o timer
            self.destroy_node()  # Destroi o nó
            rclpy.shutdown()  # Encerra o ROS

def main(args=None):
    rclpy.init(args=args)
    node = VelocityPublisher()

    try:
        # Mantém o nó rodando até que seja interrompido
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    # O nó será destruído e o ROS será encerrado dentro do método publish_velocity

if __name__ == '__main__':
    main()