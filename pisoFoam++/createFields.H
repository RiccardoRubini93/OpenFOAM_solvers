Info<< "Reading field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


// define the new variables

volVectorField U_old
(
    IOobject
    (
        "U_old",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    // initially set to 0.0
    0.0*U
);

volVectorField U_old_old
(
    IOobject
    (
        "U_old_old",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    // initially set to 0
    0.0*U
);

volVectorField U_old_old_old
(
    IOobject
    (
        "U_old_old_old",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    // initially set to 0
    0.0*U
);

// The vector field of the local eulerian accelleration
Info<< "Computing Eulerian Acceleration W\n" << endl;
volVectorField W
(
    IOobject
    (
        "W",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

#include "createPhi.H"


label pRefCell = 0;
scalar pRefValue = 0.0;
setRefCell(p, piso.dict(), pRefCell, pRefValue);
mesh.setFluxRequired(p.name());


singlePhaseTransportModel laminarTransport(U, phi);

autoPtr<incompressible::turbulenceModel> turbulence
(
    incompressible::turbulenceModel::New(U, phi, laminarTransport)
);

#include "createMRF.H"
#include "createFvOptions.H"
