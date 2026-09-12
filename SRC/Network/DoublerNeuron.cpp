#include <iostream>
#include <vector>
#include <string>


int main ()
{
    //The Input List
    std::vector<int>InputList = {-10};
    std::vector<int>TargetList = {-20};
    //Weight is zero for now
    float weight = 0;
    float LearningRate = 0.001;
    //Training 100 times
    for(int TrainingReps = 1; TrainingReps < 10000 + 1;TrainingReps ++)
    {
        std::cout << "----Training Rep :" << TrainingReps << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;

        //using this loop since both of the vectors have same size
        for(int index = 0;index < InputList.size();index ++)
        {
            //The prediction
            float prediction = InputList[index] * weight;
            std::cout << "Prediction : " << prediction << std::endl;
            //The output
            float output = TargetList[index];
            std::cout << "Output : " << output << std::endl;
            //Checking the prediction to output
            if(std::abs(prediction - output) < 0.01f)
            {
                std::cout << "It took " << TrainingReps << " Reps of Training" << std::endl;
                TrainingReps = 10001;
                break;
            }
            //To know the error
            float Error = output - prediction;
            //Adjusting the weights
            weight += LearningRate * Error * InputList[index];
            std::cout << "Weight : " << weight << std::endl;
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
        }
    }
    
    return 0;
}
