# General info
Program created for object oriented programming classes. The main goal is to simulate robot movements as 2D scene. There is also a collision schecking mechanism, collisions with robots and obstacles. I'm author of this app but middleware that connects app with GNU Plot is made by Dr.inz Bogdan Kreczmer who was a OOP course instructor at University.

# A few words about program structure

Scene is a singleton class contains all created objects in two containers  
- list contains all obstacles(robots also can be obstacles for others robots)
- vetor contains robots(for moving them)

Scene have factory methods for adding new item to one or both containers(depends on type).  
Robots obstacles and robot's path inherit form abstract class ObiektGraficzny(Graphic object).

A rotation of the robot is made using the rotation matrix, always from the reference position so as not to lose accuracy

SWektor and SMacierz are template classes that make a operation on matrices as easy as a operation on one dimension numbers

# How to use

Program requires GNU Plot, that's why it runs only on Linux.
1. Go to main catalog of repo.
2. Make directory build. `mkdir build`
3. Go to build `cd build`
4. Run comand `cmake ..`
5. Run `make`
6. Run executable file


