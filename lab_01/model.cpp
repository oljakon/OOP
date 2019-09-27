#include "model.h"

MyData InitModel()
{
    MyData model;
    model.Point_array = InitPoints();
    model.Edge_array = InitEdges();
    return model;
}

void SetModelPoints(MyData &Datapack, Points points)
{

    Datapack.Point_array = points;
}

void SetModelEdges(MyData &Datapack, Edges edges)
{
    Datapack.Edge_array = edges;
}

void SetModel(MyData &Datapack, Points points, Edges edges)
{
    SetModelPoints(Datapack, points);
    SetModelEdges(Datapack, edges);
}

void ClearModel(MyData &model)
{
    ClearEdges(model.Edge_array);
    ClearPoints(model.Point_array);
}

error_code LoadModelStream(MyData &datapack, STREAM *file_stream)
{
    error_code error_flag = ERROR_NO;

    int n_points = 0;
    int n_edges = 0;
    if ((error_flag = GetCounts(n_points, n_edges, file_stream)) != ERROR_NO)
    {
        return error_flag;
    }

    Points points;
    if ((error_flag = LoadPoints(points, n_points, file_stream)) != ERROR_NO)
    {
        return error_flag;
    }

    Edges edges;
    if ((error_flag = LoadEdges(edges, n_edges, file_stream)) != ERROR_NO)
    {
        ClearPoints(points);
        return error_flag;
    }

    SetModel(datapack, points, edges);

    return error_flag;
}

error_code LoadModel(MyData &datapack, char *filename)
{
    STREAM *file_stream = OpenFile(filename);

    if (!file_stream) return ERROR_FILE;

    MyData temp_model;

    error_code error_flag = LoadModelStream(temp_model, file_stream);
    CloseFile(file_stream);


    if (error_flag == ERROR_NO)
    {
        ClearModel(datapack);
        datapack = temp_model;
    }

    return error_flag;
}


