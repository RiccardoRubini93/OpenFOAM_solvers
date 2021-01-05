# OpenFOAM_solvers

Modified solvers for incompressible flows that output the Eulerian acceleration field. 
The acceleration is computed both as third order backward finite differences (recommended) or as the RHS of the Navier-Stokes equations.
The modal acceleration is needed as input to perform a posteriori sparsification (code available in PySparseTool)

## icoFoam++

Incompressible solver with no Turbulence modelling. It can be used to perform DNS for flow at low Reynolds Numbers

## pisoFoam+

PISO solver for incmpressible flows. This can be linked with both URANS or LES turbulence modelling.

## Solvers compiling

1) Clone the solver directory in 
```bash
~/OpenFOAM/OpenFOAM-3.0.1/applications/solvers/incompressible
```
2) In Make/files set the location where you want the executable to be compiled EXE = $(FOAM_USER_APPBIN)/NewSolver . This compile the new solver in $FOAM_USER_APPBIN instead $(FOAM_APPBIN).
3) If you need to modify Make/options as well to link the libraries you need. PS. This should not be needed.

4) Compile the new solver 
```bash
wclean && wmake
```
If the solver has been buildt succeffully you should be able to se something like this from terminal 
```bash
icoFoam++ -help

Usage: icoFoam++ [OPTIONS]
options:
  -case <dir>       specify alternate case directory, default is the cwd
  -noFunctionObjects
                    do not execute functionObjects
  -parallel         run in parallel
  -roots <(dir1 .. dirN)>
                    slave root directories for distributed running
  -srcDoc           display source code in browser
  -doc              display application documentation in browser
  -help             print the usage

Using: OpenFOAM-3.0.1 (see www.OpenFOAM.org)
Build: 3.0.1-d8a290b55d28
```
