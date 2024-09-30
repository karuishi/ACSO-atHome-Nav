#!/usr/bin/python3
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
import launch
from launch_ros.actions import LifecycleNode
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
import launch_ros.actions
from launch import LaunchDescription


import lifecycle_msgs.msg
import os

def generate_launch_description():

  

    tf2_node = Node(package='tf2_ros',
                    executable='static_transform_publisher',
                    name='static_tf_pub_laser',
                    arguments=['0', '0', '0.02','0', '0', '0', '1','base_link','laser'],
                    )
    robot_localization = launch_ros.actions.Node(
        package='robot_localization',
        executable='ekf_node',
        name='ekf_filter_node',
        output='screen',
        parameters=[os.path.join(get_package_share_directory('mane'), 'config', 'ekf.yaml')],
    )
     
    slam_toolbox = launch_ros.actions.Node(
        package='slam_toolbox',
        executable='async_slam_toolbox_node',
        name='slam_toolbox',
        output='screen',
        parameters=[{
            'use_sim_time': False,
            'base_frame': 'base_link',
            'odom_frame': 'odom',
            'map_frame': 'map',
            'laser_frame': 'laser',
        }
        ],
    )

    teleop_twist_joy = launch_ros.actions.Node(
        package='teleop_twist_joy',
        executable='teleop_node',
        name='teleop_twist_joy',
        output='screen',
        parameters=[{
            'use_sim_time': False,
            'joy_config': 'xbox',
            'axis_linear': 'left_stick_y',
            
        }
        ],
    )

    static_tf_odom = launch_ros.actions.Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='static_transform_publisher',
        output='screen',
        arguments=['0.0', '0.0', '0.0', '0', '0', '0', 'base_link', 'odom'],
    )

    rviz2 = launch_ros.actions.Node(
        package='rviz2', # rviz2 is a package in ros2 humble
        executable='rviz2', # rviz2 is a executable in ros2 humble 
        name='rviz2', # name of the node 
        output='screen', # output of the node
        parameters=[os.path.join(get_package_share_directory('mane'), 'rviz', 'config_file.rviz')],
        # open with display tf and map

    )


    
    return LaunchDescription([
        launch.actions.DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use simulation (Gazebo) clock if true'),
        tf2_node,   
        robot_localization,
        static_tf_odom,
        rviz2,
        #slam_toolbox,

    ])
