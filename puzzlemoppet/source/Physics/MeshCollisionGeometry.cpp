
#include "MeshCollisionGeometry.h"
#include "IMesh.h"

MeshCollisionGeometry::MeshCollisionGeometry(dSpaceID space, IMesh *mesh)
	: CollisionGeometry(space)
{
	meshData = ODECreateMeshData(
			mesh->GetIrrlichtNode()->getMesh()->getMesh(0),
			mesh->GetIrrlichtNode()->getScale()
			);
	
	SetODEGeom( dCreateTriMesh(space, meshData->triMeshData, nullptr, nullptr, nullptr) );
}

MeshCollisionGeometry::~MeshCollisionGeometry()
{
	delete meshData;
}

core::vector3df MeshCollisionGeometry::GetSize()
{
	return meshData->size;
}
