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

	class _CrossExport CAffectorRandom : public CAffectorBase
	{
		friend class CParticleSystem;


		// ����/��������
	protected:
		CAffectorRandom(CParticleSystem *pParent);
		virtual ~CAffectorRandom(VOID);


		// ����
	public:
		virtual TYPE GetType(VOID) const;                                                          // �������

		virtual VOID Init(VOID);                                                                   // ��ʼ��
		virtual VOID Free(VOID);                                                                   // �ͷ�

		virtual VOID LoadXML(TiXmlNode *pAffectorNode);                                            // ����XML
		virtual VOID SaveXML(TiXmlNode *pAffectorNode) const;                                      // ����XML

		virtual VOID Affect(CParticle *pParticle, FLOAT deltaTime);                                // Ӱ������

	public:
		VOID SetDirection(FLOAT minDirectionX, FLOAT minDirectionY, FLOAT minDirectionZ, FLOAT maxDirectionX, FLOAT maxDirectionY, FLOAT maxDirectionZ); // ���÷���
		VOID SetDirection(const VEC3* minDirection, const VEC3 *maxDirection);                     // ���÷���
		const VEC3* GetMinDirection(VOID) const;                                                   // �����С����
		const VEC3* GetMaxDirection(VOID) const;                                                   // ��������


		// ����
	protected:
		VEC3 m_minDirection;                                                                       // ��С�������
		VEC3 m_maxDirection;                                                                       // ����������
	};

}