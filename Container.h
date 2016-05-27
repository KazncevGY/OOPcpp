#pragma once

template <typename ContentType> class Content
{
public:
	Content(ContentType const & value)
	{
		m_value = value;
		m_next = nullptr;
	}

	Content(ContentType const & value, Content * nextElement)
	{
		m_value = value;
		m_next = nextElement;
	}

	Content()
	{
		m_value = ContentType();
		m_next = nullptr;
	}

	~Content()
	{
		delete m_next;
	}

	ContentType m_value;
	Content * m_next;
};

template <typename ContentType> class Container
{
public:

	Container()
	{
		m_numberOfElements = 0;
		m_firstElement = nullptr;
	}

	void AddFirst(ContentType const & value)
	{
		Content<ContentType> * newElement = new Content<ContentType>(value, m_firstElement);
		m_firstElement = newElement;
		++m_numberOfElements;
	}

	void AddLast(ContentType const & value)
	{
		Content<ContentType> * newElement = new Content<ContentType>(value);
		if (m_numberOfElements != 0)
		{
			Content<ContentType> * currentElement = m_firstElement;
			for (int i = 1; i < m_numberOfElements; ++i)
			{
				currentElement = currentElement->m_next;
			}
			currentElement->m_next = newElement;
		}
		else
		{
			m_firstElement = newElement;
		}
		++m_numberOfElements;
	}

	const ContentType GetFirst()
	{
		return m_firstElement->m_value;
	}

	const ContentType GetLast()
	{
		Content<ContentType> * currentElement = m_firstElement;
		for (int i = 1; i < m_numberOfElements; ++i)
		{
			currentElement = currentElement->m_next;
		}
		return currentElement->m_value;
	}

	ContentType * GetElement(int number) const
	{
		Content<ContentType> * currentElement = m_firstElement;
		while (number > 0)
		{
			currentElement = currentElement->m_next;
			--number;
		}
		return &currentElement->m_value;
	}

	void RemoveFirst()
	{
		Content<ContentType> * newBeginning = m_firstElement->m_next;
		delete m_firstElement->m_value;
		m_firstElement = newBeginning;
		--m_numberOfElements;
	}

	void RemoveLast()
	{
		Content<ContentType> * currentElement = m_firstElement;
		for (int i = 1; i < m_numberOfElements-1; ++i)
		{
			currentElement = currentElement->m_next;
		}
		delete currentElement->m_next;
		currentElement->m_next = nullptr;
		--m_numberOfElements;
	}

	void Clear()
	{
		while (m_numberOfElements>0)
		{
			RemoveFirst();
		}
	}

	bool CheckEmptiness()
	{
		return m_numberOfElements == 0;
	}

	int GetNumberOfElements() const
	{
		return m_numberOfElements;
	}
private:

	Content<ContentType> * m_firstElement;
	int m_numberOfElements;
};