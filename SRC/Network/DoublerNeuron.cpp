#include <iostream>
#include <vector>
//removed algorithm
//added cmath
#include <cmath>



float AskInput()
{
    float num;
    std::cout << "Enter the number to double with final model : "<< std::endl;
    std::cin >> num;
    return num; 
}

float FinalModel(float &num,float weight)
{
    std::cout << weight << std::endl;
    num *= weight;
    std::cout << "The Number : "<< num << std::endl;
    return num;
}


int main ()
{
    //The Input List
    std::vector<float>InputList = {-10};
    std::vector<float>TargetList = {-20};
    //Weight is zero for now
    float weight = 0;
    float LearningRate = 0.001;
    //Clean way to exit code
    bool finished{};
    //Training 100 times
    //made unsigned int
    for(unsigned int TrainingReps = 1; TrainingReps < 100 + 1;TrainingReps ++)
    {
        std::cout << "----Training Rep :" << TrainingReps << std::endl;
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;

        //using this loop since both of the vectors have same size
        //made unsigned int 
        for(unsigned int index = 0;index < InputList.size();index ++)
        {
            //The prediction
            //not making the tenth prediction only beacuse i like it this way
            float prediction = InputList[index] * weight;
            std::cout << "Prediction : " << prediction << std::endl;
            //The output
            //Changed output from target
            float Target = TargetList[index];
            std::cout << "Output : " << Target << std::endl;
            //Checking the prediction to output
            if(std::abs(prediction - Target) < 0.001f)
            {
                std::cout << "It took " << TrainingReps << " Reps of Training" << std::endl;
                finished = true;
                break;
            }
            //To know the error
            float Error = Target - prediction;
            //Adjusting the weights
            weight += LearningRate * Error * InputList[index];
            std::cout << "Weight : " << weight << std::endl;
            std::cout << "" << std::endl;
            std::cout << "" << std::endl;
        }
        if(finished)
        {
            break;
        }
    }
    float checkerNum = AskInput();
    FinalModel(checkerNum,weight);
    return 0;
}
