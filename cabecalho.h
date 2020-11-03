typedef struct {
    int day;
    int month;
    int year;
    double index;
    double date;
} Covid; 


void GraphSection(Covid *v, int N);
float LinearSearch(int d, int m, int y, Covid *v, int N);
float quickSort(int n, Covid *vetor, int esquerda, int direita);
