#include "tiny_obj_loader.h"

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>

// gets base path then appends material path to the base path
char* getMtlPath(const char* path, char* mat){
  
  char* p;
  int size = 0;

  p = strrchr(path, '/');
  if(p){
    int start = p-path+1;
    size += start + 2 + strlen(mat); // the two is for the slash and the final end-of-string \0 character
    char* mtlPath = (char*) malloc(size);
    strcpy(mtlPath, path+start);
    strcat(mtlPath, "/");
    strcat(mtlPath, mat);
    return mtlPath;
  } else { // no base path, so we just return the string
    // allocate so we can always perform "free" later
    char* mtlPath = (char*) malloc(strlen(mat));
    return strcpy(mtlPath, mat);
  }
}

int
main(
  int argc,
  char **argv)
{
  char* matlPath = getMtlPath("test.obj", "test.mat");
  // char* matlPath = getMtlPath("rain/something/test.obj", "test.mat");
  printf("matpath: %s\n", matlPath);
  printf("sizeof matpath: %i\n", strlen(matlPath));
  // char path[] = "rain/something/test.obj";
  // // char path[] = "test.obj";
  // char basePath[4096];
  // strcpy (basePath, path);

  // char *p;
  // p = strrchr(basePath, '/');
  // if(p){
  //   p[0] = '\0';
  // } else {
  //   basePath[0] = '\0';
  // }
  // printf("path: %s\n", basePath);

  // char mat[] = "mat.mtl";
  // char matPath[4096];
  // strcpy(matPath, basePath);
  // strcat(matPath, "/");
  // strcat(matPath, mat);
  // printf("mat path: %s\n", matPath);


  // std::string inputfile = "obj/cornell_box.obj";
  // std::vector<tinyobj::shape_t> shapes;

  // if (argc > 1) {
  //   inputfile = std::string(argv[1]);
  // }
  
  // std::string err = tinyobj::LoadObj(shapes, inputfile.c_str());

  // if (!err.empty()) {
  //   std::cerr << err << std::endl;
  // }

  // std::cout << "# of shapes : " << shapes.size() << std::endl;

  // for (size_t i = 0; i < shapes.size(); i++) {
  //   printf("shape[%ld].name = %s\n", i, shapes[i].name.c_str());
  //   printf("shape[%ld].indices: %ld\n", i, shapes[i].mesh.indices.size());
  //   assert((shapes[i].mesh.indices.size() % 3) == 0);
  //   for (size_t f = 0; f < shapes[i].mesh.indices.size(); f++) {
  //     printf("  idx[%ld] = %d\n", f, shapes[i].mesh.indices[f]);
  //   }

  //   printf("shape[%ld].vertices: %ld\n", i, shapes[i].mesh.positions.size());
  //   assert((shapes[i].mesh.positions.size() % 3) == 0);
  //   for (size_t v = 0; v < shapes[i].mesh.positions.size() / 3; v++) {
  //     printf("  v[%ld] = (%f, %f, %f)\n", v,
  //       shapes[i].mesh.positions[3*v+0],
  //       shapes[i].mesh.positions[3*v+1],
  //       shapes[i].mesh.positions[3*v+2]);
  //   }
  
  //   printf("shape[%ld].material.name = %s\n", i, shapes[i].material.name.c_str());
  //   printf("  material.Ka = (%f, %f ,%f)\n", shapes[i].material.ambient[0], shapes[i].material.ambient[1], shapes[i].material.ambient[2]);
  //   printf("  material.Kd = (%f, %f ,%f)\n", shapes[i].material.diffuse[0], shapes[i].material.diffuse[1], shapes[i].material.diffuse[2]);
  //   printf("  material.Ks = (%f, %f ,%f)\n", shapes[i].material.specular[0], shapes[i].material.specular[1], shapes[i].material.specular[2]);
  //   printf("  material.Tr = (%f, %f ,%f)\n", shapes[i].material.transmittance[0], shapes[i].material.transmittance[1], shapes[i].material.transmittance[2]);
  //   printf("  material.Ke = (%f, %f ,%f)\n", shapes[i].material.emission[0], shapes[i].material.emission[1], shapes[i].material.emission[2]);
  //   printf("  material.Ns = %f\n", shapes[i].material.shininess);
  //   printf("  material.map_Ka = %s\n", shapes[i].material.ambient_texname.c_str());
  //   printf("  material.map_Kd = %s\n", shapes[i].material.diffuse_texname.c_str());
  //   printf("  material.map_Ks = %s\n", shapes[i].material.specular_texname.c_str());
  //   printf("  material.map_Ns = %s\n", shapes[i].material.normal_texname.c_str());
  //   std::map<std::string, std::string>::iterator it(shapes[i].material.unknown_parameter.begin());
  //   std::map<std::string, std::string>::iterator itEnd(shapes[i].material.unknown_parameter.end());
  //   for (; it != itEnd; it++) {
  //     printf("  material.%s = %s\n", it->first.c_str(), it->second.c_str());
  //   }
  //   printf("\n");
  // }

  free(matlPath);

  return 0;
}
