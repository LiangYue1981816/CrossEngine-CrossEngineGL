/****************************************************************************
Copyright (c) 2015 LiangYue.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sub license, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#pragma once


#include "CrossEngine.h"


namespace CrossEngine {

	template<class T> class _CrossExport CSharedPtr
	{
		// 构造/析构函数
	public:
		CSharedPtr(VOID)
			: m_pPointer(NULL)
			, m_pRefCount(NULL)
		{

		}
		CSharedPtr(const T *pPointer)
			: m_pPointer(NULL)
			, m_pRefCount(NULL)
		{
			Set(pPointer, NULL);
		}
		CSharedPtr(const CSharedPtr &share)
			: m_pPointer(NULL)
			, m_pRefCount(NULL)
		{
			Set(share.m_pPointer, share.m_pRefCount);
		}
		virtual ~CSharedPtr(VOID)
		{
			SetNull();
		}


		// 方法
	protected:
		inline VOID Set(const T *pPointer, const DWORD *pRefCount)
		{
			if (m_pPointer != pPointer) {
				SetNull();

				m_pPointer = (T *)pPointer;
				m_pRefCount = (DWORD *)pRefCount;

				if (m_pRefCount == NULL) {
					m_pRefCount = (DWORD *)SAFE_MALLOC(sizeof(*m_pRefCount), MEMTYPE_HEAP);
					ASSERT(m_pRefCount);

					*m_pRefCount = 0;
				}

				++(*m_pRefCount);
			}
		}

		virtual VOID FreePointer(VOID) = 0;

	public:
		inline CSharedPtr& operator = (const CSharedPtr &share)
		{
			Set(share.m_pPointer, share.m_pRefCount);
			return *this;
		}

		inline T* operator -> (VOID) const
		{
			return m_pPointer;
		}

		inline BOOL IsNull(VOID) const
		{
			return m_pPointer && m_pRefCount ? FALSE : TRUE;
		}

		inline VOID SetNull(VOID)
		{
			if (m_pRefCount) {
				if (--(*m_pRefCount) == 0) {
					SAFE_FREE(m_pRefCount);
					FreePointer();
				}
			}

			m_pPointer = NULL;
			m_pRefCount = NULL;
		}

		inline T* GetPointer(VOID) const
		{
			return m_pPointer;
		}

		inline DWORD* GetRefCount(VOID) const
		{
			return m_pRefCount;
		}


		// 属性
	protected:
		T *m_pPointer;
		DWORD *m_pRefCount;
	};

}
