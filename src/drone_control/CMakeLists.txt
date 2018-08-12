cmake_minimum_required(VERSION 2.8.3)
project(drone_control)


## catkinビルドに必要なコンポーネントパッケージの設定
## これらのパッケージが存在しない場合、catkinビルドの途中でエラーが出る。
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs)

## インクルードディレクトリ、ライブラリ、catkinビルド、システムに依存するパッケージの指定
catkin_package(
# INCLUDE_DIRS include
 LIBRARIES drone_control
 CATKIN_DEPENDS roscpp std_msgs
# DEPENDS system_lib
)

## インクルードディレクトリの設定
include_directories(
${catkin_INCLUDE_DIRS}
)

## 実行ファイル、ターゲットリンクライブラリ、追加の依存関係などを設定
 add_executable(drone_control_node  src/drone_control.cpp)
 target_link_libraries(drone_control_node
   ${catkin_LIBRARIES}
 )

