#ifndef FILTER_H
#define FILTER_H

class Filter
{
private:
    float *m_data;
    int m_size;
    int m_maxSize;
    int m_insert;

public:
    Filter(int bufferSize);

    float GetAverage();
    float Add(float data);

    void GetDataInOrder(float *out, int *size);
};

#endif // FILTER_H
