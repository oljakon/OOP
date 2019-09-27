#include "uploader.hpp"

model_uploader::model_uploader(const std::string& fileName) : fileName(fileName) {}

std::shared_ptr<Model> model_uploader::upload_model(base_builder& bld)
{
    try
    {
        bld.build_model();

        size_t count_nodes;
        double x, y, z;

        file >> count_nodes;

        for (size_t i = 0; i < count_nodes; ++i)
        {
            file >> x >> y >> z;
            bld.build_node(x, y, z);
        }

        size_t count_edges;
        size_t src, purp;

        file >> count_edges;

        for (size_t i = 0; i < count_edges; ++i)
        {
            file >> src >> purp;
            bld.build_edge(src, purp);
        }

    }
    catch (const std::ifstream::failure& e)
    {
        throw ReadFileException();
    }

    return bld.get_model();
}

void model_uploader::open()
{
    this->file.open(this->fileName);
    if (!file)
        throw OpenFileException();
}

void model_uploader::close()
{
    try
    {
        this->file.close();
    }
    catch (const std::ifstream::failure& e)
    {
        throw CloseFileException();
    }
}
