#ifndef MODEL
#define MODEL

#include "points.h"
#include "edges.h"
#include "counts.h"
#include "file.h"

struct MyData
{
    struct MyPoint centre;
    struct Points Point_array;
    struct Edges Edge_array;
};

void SetModelPoints(MyData &Datapack, Points points);
void SetModelEdges(MyData &Datapack, Edges edges);
void SetModel(MyData &Datapack, Points points, Edges edges);
void ClearModel(MyData &model);
error_code LoadModelStream(MyData &datapack, STREAM *file_stream);
error_code LoadModel(MyData &datapack, char *filename);
MyData InitModel();

#endif
