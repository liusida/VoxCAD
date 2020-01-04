# VoxCAD

Use QT5 Creator as IDE, instead of Visual Studio.

## Notes for steps

1. Create a robot.

1.1 "Tools"->"Edit Voxels"; 

1.2 Choose the right "Palette" (Or we should call that "Material"); 

1.3 Use "Pencil", "Rectangle", etc. to draw what you want. (Sometimes there's a bug in Depth so users cannot draw.)

1.4 Use "Layer Back" before drawing another layer.

2. Cancel "Fix All"

2.1 "Analyze"->"Boundary Conditions";

2.2 Choose Boundary Condition BC0(*******), click "Fix None";

2.3 Click "Finished Editing".

3. Run Simulation

3.1 "Analyze"->"Physics Sandbox"

3.2 "timestep (% optimal dt)" should be set to about "0.01"

4. Enable Actuation

4.1 Click one certain "Palette" (or "Material") and select Tab "Physical".

4.2 Change "CTE (1/deg C)" (which means Coefficient of Thermal Expansion, Unit: 1/degrees celsius) to like "0.01"

4.3 In "Physics Sandbox", select Tab "Physics Setting"->Tab "Environment", check "Vary Temperature" and set value to like "5e-05".

4.4 Change "Temp (deg C)" to like "40".

Now you can see your robot moving.

Wrong order may cause "Segmentation fault" error. :(

