#ifndef NDARRAY_H_
#define NDARRAY_H_
#include <stdarg.h>
#include <vector>


namespace ncu {
    template<typename T>
    class NdArray {
        private:
        std::vector<T> data;
        std::vector<size_t> shape;

        public:
        NdArray(int nargs, ...);
        ~NdArray(void);
    };

    template<typename T>
    NdArray<T>:: NdArray(int nargs, ...)
    {
        va_list ap;
        va_start(ap, nargs);
        for(int i = 0; i < nargs; ++i){
            int dim_i = va_arg(ap, int);
            this->shape.push_back(dim_i);
        }
        va_end(ap);
    }


    template<typename T>
    NdArray<T>::~NdArray(void)
    {
        this->shape.clear();
        this->data.clear();
    }

} // namespace ncu

#endif // NDARRAY_H_
