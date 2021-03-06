/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Written (W) 2013 Soumyajit De
 */

#ifndef VECTOR_RESULT_H_
#define VECTOR_RESULT_H_

#include <shogun/lib/config.h>
#include <shogun/lib/SGVector.h>
#include <shogun/lib/computation/job/JobResult.h>
#include <shogun/base/Parameter.h>

namespace shogun
{
/** @brief Base class that stores the result of an independent job
 * when the result is a vector.
 */
template<class T> class CVectorResult : public CJobResult
{
/** this class supports complex */
typedef bool supports_complex64_t;

public:
	/** default constructor */
	CVectorResult()
	: CJobResult()
	{
		init();
		SG_GCDEBUG("%s created (%p)\n", this->get_name(), this)
	}

	/** constructor
	 * @param result the vector result
	 */
	CVectorResult(SGVector<T> result)
	: CJobResult(), m_result(result)
	{
		init();
		SG_GCDEBUG("%s created (%p)\n", this->get_name(), this)
	}

	/** destructor */
	virtual ~CVectorResult()
	{
		SG_GCDEBUG("%s destroyed (%p)\n", this->get_name(), this)
	}

	/** @return object name */
	virtual const char* get_name() const
	{
		return "VectorResult";
	}

	/** @return the job result */
	SGVector<T> get_result() const
	{
		return m_result;
	}

protected:
	/** the vector result */
	SGVector<T> m_result;

private:
	/** initialize with default values and register params */
	void init()
	{
		set_generic<T>();

		SG_ADD(&m_result, "result",
			"The result vector", MS_NOT_AVAILABLE);
	}
};

template class CVectorResult<bool>;
template class CVectorResult<char>;
template class CVectorResult<int8_t>;
template class CVectorResult<uint8_t>;
template class CVectorResult<int16_t>;
template class CVectorResult<uint16_t>;
template class CVectorResult<int32_t>;
template class CVectorResult<uint32_t>;
template class CVectorResult<int64_t>;
template class CVectorResult<uint64_t>;
template class CVectorResult<float32_t>;
template class CVectorResult<float64_t>;
template class CVectorResult<floatmax_t>;
template class CVectorResult<complex64_t>;

}

#endif // VECTOR_RESULT_H_
