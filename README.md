# minirt_parser
A file parser.

## 🧐 About
This program takes a given file with extension `.rt`:
```
A 0.2 255,255,255

C -50,0,20 0,0,0 70

L -40,0,30 0.7 255,255,255
L -40,0,30 0.7 255,255,255
L -40,0,30 0.7 255,255,255

pl 0,0,0 0,1.0,0 255,0,225
sp 0,0,20 20 255,0,255
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
```
and parses it into a C struct.:
```
typedef struct s_scene_light_param
{
	double                        *l_light_point;
	double                        l_britghness;
	double                        *l_color;
	struct s_scene_light_param    *next;
}	t_scene_light_param;

typedef struct s_scene_object_param
{
	char                          *identifier;
	double                        *cordinates;
	double                        *color;
	double                        *orientation_vector;
	double                        diameter;
	double                        height;
	struct s_scene_object_param   *next;
}
```
This project is part of 42 École/ 42 SP curriculum.

## 🏫 42 École | 42 São Paulo
42 École is a network of tech schools spread around the world where anyone can learn how to code for free.\
At 42 there are no teachers or classrooms, each student learns from and works with each other (peer-to-peer learning).\
To see more go to https://www.42.fr/ and https://www.42sp.org.br/.
