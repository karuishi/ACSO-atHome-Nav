import os

from ament_index_python.packages import get_package_share_directory


from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

from launch_ros.actions import Node


def generate_launch_description():


    # Include the robot_state_publisher launch file, provided by our own package. Force sim time to be enabled
    # !!! MAKE SURE YOU SET THE PACKAGE NAME CORRECTLY !!!

    package_name='mane' #<--- CHANGE ME

    rsp = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory(package_name),'launch','rsp.launch.py'
                )]), launch_arguments={'use_sim_time': 'true'}.items()
    )

    # Include the Gazebo launch file, provided by the gazebo_ros package
    gazebo = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')]),
             )

    # Run the spawner node from the gazebo_ros package. The entity name doesn't really matter if you only have a single robot.
    spawn_entity = Node(package='gazebo_ros', executable='spawn_entity.py',
                        arguments=['-topic', 'robot_description',
                                   '-entity', 'my_bot'],
                        output='screen')   
    
    # Include rviz2 below after creating the view.rviz file or something similar.
    # rviz2 = Node(
    #     package='rviz2',
    #     namespace='',
    #     executable='rviz2',
    #     name='rviz2',
    #     arguments=['-d', [os.path.join(pkg_dir, 'config', 'config_file.rviz')]]
    # )

    robot_localization = Node(
        package = 'robot_localization',
        executable = 'ekf_node',
        name = 'ekf_filter_node',
        output = 'screen',
        parameters = [os.path.join(package_name, 'config/ekf.yaml'), {'use_sim_time': True}]
    )


    # Launch them all!
    return LaunchDescription([
        rsp,
        gazebo,
        spawn_entity,
        robot_localization,
        # rviz2,
    ])
