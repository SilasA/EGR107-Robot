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
};

#endif FILTER_H
