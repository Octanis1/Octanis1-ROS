## Node of communication
# Prepare the node
To prepare this node, make the scripts become excecutable (chmod +x my\_script.py) and build the workspace (go to catkin\_ws and use the command-line catkin\_make)

Don't forget to use the command-line 'source ./devel/setup.bash' (when you're in the folder catkin\_ws) if it's not in your bashrc.

# Execution
run roscore in one terminal (command-line: roscore)

run the talker.py in another terminal (command-line: rosrun node_communication talker.py)

run the listener.py in a third terminal (command-line: rosrun node_communication listener.py)

Then, you will see the interpretation of the 'positions of the joints' sent by the talker. (See the function 'Callback' to understand what is printed).
