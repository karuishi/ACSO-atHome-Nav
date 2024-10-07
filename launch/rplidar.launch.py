import os 
from launch import LaunchDescription
from launch.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package = 'lslidar_driver',
            executable = 'lslidar_driver_node',
            output = 'screen',
            parameters = [{
                'serial_port': '/dev/serial/by-path/platform-fd500000.pcie-pci-0000:01:00.0-usb-0:1.3:1.0-port0',
                'frame_id': 'lidar_link',
                'angle_compensate': True,
                'scan_mode':'Standard'
            }]
        )
    ])