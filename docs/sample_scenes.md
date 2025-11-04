# Sample `.rt` Scenes

The `scenes/` directory contains ready-to-use examples you can feed to `miniRT` while developing or testing the renderer. Each file respects the project parser expectations (one ambient light, one camera, one point light, and a selection of objects).

## Available scenes

| File | Highlights |
| --- | --- |
| `basic_sphere.rt` | Minimal setup with a single red sphere for quick smoke tests. |
| `plane_and_spheres.rt` | Adds a ground plane and two spheres to validate shadows and multiple shapes. |
| `cylinder_showcase.rt` | Mixes a cylinder with supporting spheres for intersection debugging. |

## How to launch

Run `miniRT` with the desired file:

```bash
./miniRT scenes/basic_sphere.rt
```

> **Tip:** On headless environments, wrap the command with `timeout` (for example `timeout 2 ./miniRT scenes/basic_sphere.rt`) so the program exits automatically once you have confirmed the scene loads.
