#include "Filter.h"

Filter::Filter(int bufferSize)
{
    m_data = new float[bufferSize];
    m_maxSize = bufferSize;
    m_size = 0;
    m_insert = 0;
}

float Filter::GetAverage()
{
    float avg = 0;
    for (int i = 0; i < m_size; i++)
        avg += m_data[i];
    return avg / m_size;
}

float Filter::Add(float data)
{
    m_data[m_insert++] = data;
    m_insert %= m_maxSize;
    m_size++;
    if (m_size > m_maxSize) m_size = m_maxSize;
}

void Filter::GetDataInOrder(float *out, int *size)
{
  out = new float[m_size];
  size = m_size;
  int start = m_insert - 1;
  if (m_insert - 1 < 0)
    start = m_size - 1;

  for (int i = 0; i < m_size; i++)
    out[i] = m_data[(start + i) % m_size];


}
