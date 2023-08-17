long factorial(int num)
{
    long result = 1;
    //for(int i = num; i>0; --i) //정순
    for (int i = 1; i <= num; ++i) //역순
    {
        result = result * i;
    }
    return result;
}