#ifndef SHARED_HPP
# define SHARED_HPP

#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <vector>

template <class T> struct sharedBlock
{
	T* ptr;
	size_t sharedCounter;
	size_t weakCounter;
};

template <class T> class SharedPtr
{
	sharedBlock<T>* block;
	void copy(const SharedPtr& other)
	{
		this->block = other.block;
		if (block)
			block->sharedCounter++;
	}
	void clean()
	{
		if (block)
		{
			if (!--block->sharedCounter)
			{
				if (block->ptr)
					delete block->ptr;
				block->ptr = NULL;
			}
			if (!block->weakCounter && !block->ptr)
			{
				delete block;
				block = NULL;
			}
		}
	}

	public:
		SharedPtr(T* pointer)
		{
			block = pointer? new sharedBlock<T>{pointer, 1, 0} : NULL;
		}

		~SharedPtr() { clean(); };

		SharedPtr(const SharedPtr& other) { copy(other); }

		SharedPtr& operator=(std::nullptr_t) { clean(); }

		SharedPtr& operator=(const SharedPtr& other)
		{
			clean();
			copy(other);
			return *this;
		}

		T&	operator*() { return *get(); };
		T*	operator->() { return get(); }

		const T&	operator*() const {return *get(); }
		const T*	operator->() const { return get(); }

		size_t user_count() const { return block? block->sharedCounter : 0; }

		const T*	get() const { return block? block->ptr : NULL; }

		T*	get() { return block? block->ptr : NULL; }

		void	swap(SharedPtr& other)
		{
			sharedBlock<T>* block = other.block;
			other.block = this->block;
			this->block = block;
		}

		void	reset() { clean(); }

		void	reset(T* ptr) { block = new sharedBlock<T>{ptr, 1, 0}; }

		bool	owner_before(const SharedPtr& other) const { return this < &other; }
};

#endif
