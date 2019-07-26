void Push(arraystack S, ELementType item)
{
    if( S->Top == MAXSIZE - 1)
    {
        printf("Stack is full!\n");
        return;
    }
    else
    {
        S->Data[++(S->Top)] = item;
        return;
    }
}

ELementType Pop(arraystack S)
{
    if( S->Top == -1 )
    {
        printf("Stack is empty!\n");
        return ERROR;
    }
    else
        return S->Data[(S->Top)--];
}
