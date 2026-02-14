*This project has been created as part of the 42 curriculum by jsurian, srenaud*

# MiniRT

## Description
This project is called miniRT. Its purpose is to generate 3D scenes from .rt scene files using the raycasting method. It is an introduction to raytracing, allowing the rendering of simple computer-generated images with basic geometric objects (planes, spheres, cylinders), lighting (ambient and diffuse), and shadows.

## Instructions
To install this project, git clone the repository and then compile using `make`. To run, `./miniRT <path/scene_name.rt>`.

## Resources
- http://raytracerchallenge.com/ — introduction to the concept
- CRM FormulairesEtTables — basics of geometry theory
- https://medium.com/@iremoztimur/building-a-minirt-42-project-part-1-ae7a00aebdb9 — sphere intersections
- https://davidjcobb.github.io/articles/ray-cylinder-intersection — cylinder intersection
- https://medium.com/@iremoztimur/minirt-shading-algorithms-part-2-6c46e6d81fbd — shading theory
- https://en.wikipedia.org/wiki/Lambertian_reflectance — shading
- 42 peers
- We used AI to understand concepts like how to render shadows without glitches (Epsilon)
- At the end, we encountered a specific issue with the camera on the Y-axis. We used AI to find a solution and implemented the few lines suggested. We fully understand this code.

## Additional Information
As expected by the project, we use the minilibx to get a window and pixels addresses. We chose the geometrical vector approach and not the matricial one because at the beginning it was easier to understand, but at the end we regretted a bit this choice.
