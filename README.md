# Minimal Refman Disk Simulation
<p align="center">
<img width="500" alt="image" src="https://github.com/user-attachments/assets/8cebbe14-f6de-4d6b-870a-07f332bde225" />
</p>

## Description

Repairing a corrupted C++ codebase (with destroyed headers and corrupted ".cpp" sections) so the simulation can run for ***>= 1000 steps*** (default settings produce 10000) without crashing, and an output can be ***visualised using the provided python viewer*** (view.py / view.ipynb).

The simulation models the motion of hard disks within a 2D box with hard-wall boundaries. Each step assumes random displacements. Movements which would cause overlaps or leave the box are rejected.

The goal is to reconstruct and repair the destroyed header and corrupted source files, which are needed to simulate the random motion of hard disks.

## Project Structure
- `main.cpp`
  - Parses user-inputted parameters, runs the simulation loop and writes the simulation to ***confs/***
- `system.h / system.cpp`
  - Manages the construction, movement, overlap checks, boundary enforcement and saving output of the program
- `disk.h / disk.cpp`
  - Manages each disk's construction, position, displacement, and distance from other disks
- `view.py / view.ipynb`
  - Reads the configurations produced and animates the disk positions using Python and Matplotlib
- `instructions.html / refman.pdf`
  - Reference manual/specifications for the project
 
## How it works (overview)

Each iteration:
1. Proposes a random displacement for each disk (up to `maxDisplacement`).
2. Enforces hard-wall boundaries (disks remain inside the box).
3. Rejects any move that causes disk–disk overlap.
4. Saves the current configuration to `confs/confN`.

## Improvements Added
- Added CLI so users can input their own data for each simulation ***[NumberOfDisks maxDisplacement Radius BoxSize]***
- Better encapsulation of disk.h and system.h files
- Disk boundary logic changed so disks stay within the box at all times
- Added axis labels to the view

## Dependencies

**C++**
- **C++17-capable compiler (e.g., g++)**

**Python (for visualisation)**
- **Python 3 (for view.py / view.ipynb)**
- numpy
- matplotlib

```bash
python3 -m pip install numpy matplotlib
```

## Build the program
Compile the project:
```bash
make
```
or for clean build outputs
```bash
make clean
```

## Run the program
Run using Makefile
```bash
make run
```
or run directly
```bash
mkdir -p confs
./prog
```
Command-line arguments
```bash
./prog NumberOfDisks maxDisplacement Radius BoxSize
```
Parameter meanings: 
- NumberOfDisks — number of disks (default: 20) 
- maxDisplacement — max trial displacement per step in x/y (default: 0.6) 
- Radius — radius of each disk (default: 0.5) 
- BoxSize — side length of the square box (default: 20.0)

Example (default values):
```bash
./prog 20 0.6 0.5 20
```

## Output Format
Each simulation step is saved as a configuration file in `confs/`:
- `confs/conf0, confs/conf1, confs/conf2, ...`

Each file is in plain text:
- Line 1: number of disks N
- Line 2: comment line
Then one line per disk:
```text
A x y r
```
where ***x, y are the disk centre coordinates*** and ***r is the radius.***

## Visualise Output

After running the simulation (so `confs/` contains `conf*` files):

```bash
python3 view.py
```
The following should appear:

<table>
  <tr>
    <td>
      <img width="320" alt="Starting Disk graphic"
           src="https://github.com/user-attachments/assets/213f181b-f23a-4e32-ab7e-d5ecf3bd7914" />
    </td>
    <td>
      <img width="320" alt="Disk graphic"
           src="https://github.com/user-attachments/assets/d089e65b-9feb-4c28-91ec-4066390a9019" />
    </td>
  </tr>
</table>

Where the disks transition across the screen through random motion.

## Git / Setup

```bash
git clone https://github.com/Chickolas/Refman-Disk-Simulation.git
cd Refman-Disk-Simulation/package-for-students
make
make run
python3 view.py
```

## Troubleshooting

- ***No files matched `confs/c*`***  
  Run the simulation first (`make run`) to generate `conf*` files.

- ***Missing Python packages***
  Install dependencies: `python3 -m pip install numpy matplotlib`

- ***Unable to make program***
  ensure you are in the right directory: `cd Refman-Disk-Simulation/package-for-students`


