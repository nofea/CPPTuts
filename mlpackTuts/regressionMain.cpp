#include <iostream>
#include <fstream>
#include <mlpack/core/data/load.hpp>
#include <mlpack/methods/linear_regression/linear_regression.hpp>

using namespace std;
using namespace mlpack;

int main()
{
    arma::mat predictor_data;
    arma::rowvec response_data = {0,1,3,6,4,8,5,-1};
    arma::rowvec predictions;
    string WorkingDirectory("/mnt/c/projectenv/CPPTuts/mlpackTuts/");

    try
    {
        //data::Load(WorkingDirectory+"training_data.csv", predictor_data);
        //data::Load(WorkingDirectory+"response_data.csv", response_data);
        predictor_data.load("../training_data.mat");
        //fileIn.open("training_data.txt");
        //predictor_data = predictor_data.t();
        //fileIn >> iPlayer >> iMove;

        /* while (fileIn)
        {
            fileIn >> iPlayer >> iMove;
            cout << iPlayer << " " << iMove << endl;
        }
        cout << iPlayer << " " << iMove << endl; */       
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    cout << predictor_data << endl;
    cout << response_data << endl;
    
    //fileIn.close();
   // data::Load("response_data.csv", response_data);

    regression::LinearRegression lr;

    cout << "Train Model" << endl;
    lr.Train(predictor_data, response_data);

    cout << "Predict" << endl;
    lr.Predict(predictor_data, predictions);

    try
    {
        //data::Save(WorkingDirectory+"prediction_data.csv", static_cast<arma::mat>(predictions));
        //predictions.save("../prediction_data.csv");
        cout << "prediction:" << endl;
        cout << predictions << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    //cout << predictions << endl;

    return 0;
}