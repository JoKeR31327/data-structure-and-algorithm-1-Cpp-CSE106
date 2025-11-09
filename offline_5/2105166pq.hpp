#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class priorityqueue
{
private:
    T *ar;
    int len = 0;

    void maxheapify(T *A, int i)
    {
        int left = 2 * i;
        int right = left + 1;
        int large = i;
        int highest = A[i];
        if (left <= len && highest < A[left])
        {
            large = left;
            highest = A[left];
        }
        if (right <= len && highest < A[right])
        {
            large = right;
            highest = A[right];
        }
        if (large != i)
        {
            T temp = A[i];
            A[i] = A[large];
            A[large] = temp;
            maxheapify(A, large);
        }
    }

    void buildheap(T *A)
    {
        int index = len;
        while (index / 2 > 0 && A[index] > A[index / 2])
        {
            T temp = A[index];
            A[index] = A[index / 2];
            A[index / 2] = temp;
            index /= 2;
        }
    }

public:
    priorityqueue()
    {
        ar = new T[100];
    }

    ~priorityqueue()
    {
        delete[] ar;
    }

    void insert(T x)
    {
        len++;
        ar[len] = x;
        buildheap(ar);
    }

    bool findmax(T &maxElement, ofstream &outfile)
    {
        if (len > 0)
        {
            maxElement = ar[1];
            return true;
        }
        else
        {
            outfile << "Priority queue is empty" << endl;
            return false;
        }
    }

    bool ExtractMax(T &maxElement, ofstream &outfile)
    {
        if (len <= 0)
        {
            outfile << "Priority queue is empty" << endl;
            return false;
        }
        maxElement = ar[1];
        ar[1] = ar[len];
        len--;

        maxheapify(ar, 1);

        return true;
    }

    bool increasekey(int i, const T &newkey, ofstream &outfile)
    {
        if (newkey < ar[i])
        {
            outfile << "New key is not larger than the previous key" << endl;
            return false;
        }
        ar[i] = newkey;
        while (i > 1 && ar[i] > ar[i / 2])
        {
            T temp = ar[i];
            ar[i] = ar[i / 2];
            ar[i / 2] = temp;
            i /= 2;
        }
        return true;
    }

    bool decreasekey(int i, const T &newkey, ofstream &outfile)
    {
        if (newkey > ar[i])
        {
            outfile << "New key is not smaller than the previous key" << endl;
            return false;
        }
        ar[i] = newkey;
        maxheapify(ar, i);
        return true;
    }

    bool Sort(ofstream &outfile)
    {
        // for (int i = len / 2; i >= 1; --i)
        // {
        //     maxheapify(ar, i);
        // }
        int length = len;
        for (int i = len; i >= 2; --i)
        {
            T temp = ar[i];
            ar[i] = ar[1];
            ar[1] = temp;
            len--;
            maxheapify(ar, 1);
        }
        while (len > 1)
        {
            swap(ar[1], ar[len]);
            len--;
            maxheapify(ar, 1);
        }
        outfile << "No of elements: " << length << std::endl;
        if (length > 0)
        {
            int level = 1;
            int levelsize = 1;
            int current = 0;

            for (int i = 1; i <= length; ++i)
            {
                outfile << ar[i] << "\t";

                current++;
                if (current == levelsize)
                {
                    outfile << endl;
                    level++;
                    levelsize *= 2;
                    current = 0;
                }
            }
            // outfile << size();
        }
        else
        {
            outfile << "Priority queue is empty" << endl;
        }
        return true;
    }
    int size()
    {
        return len;
    }
    void Print(ofstream &outfile)
    {
        if (len > 0)
        {
            int level = 1;
            int levelsize = 1;
            int current = 0;

            for (int i = 1; i <= len; ++i)
            {
                outfile << ar[i] << "\t";

                current++;
                if (current == levelsize)
                {
                    outfile << endl;
                    level++;
                    levelsize *= 2;
                    current = 0;
                }
            }
        }
        else
        {
            outfile << "Priority queue is empty" << endl;
        }
    }
};