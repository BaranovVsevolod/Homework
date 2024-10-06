class DynamicArr {
	static const size_t initialCapacity_ = 2;	// only one for all objects of DynamicArr
	static const double coeff_;					// same as above

	size_t size_ = 0;
	size_t capacity_ = initialCapacity_;
	double* arr_;

public:
	DynamicArr() {
		arr_ = new double[capacity_];
	}

	DynamicArr(size_t size, double elem = 0) : size_(size)
	,capacity_(coeff_* size_)
	,arr_(new double[capacity_]) {
		for (size_t i = 0; i < size_; ++i) {
			arr_[i] = elem;
		}
	}

	DynamicArr(const DynamicArr& rhs) {
		size_ = rhs.size_;
		capacity_ = rhs.capacity_;
		arr_ = new double[capacity_];
		for (size_t i = 0; i < size_; ++i) {
			arr_[i] = rhs.arr_[i];
		}
	}

	~DynamicArr() {
		delete[] arr_;
	}

	size_t size() const {
		return size_;
	}

	size_t capacity() const {
		return capacity_;
	}

	void push_back(double elem) {
		if (size_ == capacity_) {
			capacity_ = coeff_ * capacity_;
			double* tmp = new double[capacity_];
			for (size_t i = 0; i < size_; ++i) {
				tmp[i] = arr_[i];
			}
			delete[] arr_;
			arr_ = tmp;
		}
		arr_[size_++] = elem;
	}

	void operator= (const DynamicArr& rhs) {
		size_ = rhs.size_;
		capacity_ = rhs.capacity_;
		arr_ = new double[capacity_];
		for (size_t i = 0; i < size_; ++i) {
			arr_[i] = rhs.arr_[i];
		}
	}

	double& operator [] (int index) {
		return arr_[index];
	}
};