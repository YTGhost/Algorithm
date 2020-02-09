bool checkIfExist(int* arr, int arrSize){
    int i, j;
    for(i = 0; i < arrSize; i++){
        for(j = 0; j < arrSize ; j++){
            if(2 * arr[i] == arr[j] && i!=j){
                return true;
            }
        }
    }
    return false;
}