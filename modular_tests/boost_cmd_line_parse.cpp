#include <iostream>
#include <iterator>
#include <boost/program_options.hpp>
#include <exception>

namespace po = boost::program_options;

int main(int argc, char** argv){

    try
    {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce help message")
            ("compression", po::value<double>(), "set compression level");

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help"))
        {
            std::cout << desc << "\n";
            return 0;
        }

        if (vm.count("compression"))
        {
            std::cout << "Compression level was set to "
                << vm["compression"].as<double>() << ".\n";
        }
        else
        {
            std::cout << "Compression level was not set.\n";
        }
    }
    catch(exception& e)
    {
        std::cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...)
    {
        std::cerr << "Exception of unknown type!\n";
        return 1;
    }

    return 0;
}