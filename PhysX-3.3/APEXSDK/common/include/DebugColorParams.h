/*
 * Copyright (c) 2008-2015, NVIDIA CORPORATION.  All rights reserved.
 *
 * NVIDIA CORPORATION and its licensors retain all intellectual property
 * and proprietary rights in and to this software, related documentation
 * and any modifications thereto.  Any use, reproduction, disclosure or
 * distribution of this software and related documentation without an express
 * license agreement from NVIDIA CORPORATION is strictly prohibited.
 */


// This file was generated by NxParameterized/scripts/GenParameterized.pl
// Created: 2015.10.22 17:26:18

#ifndef HEADER_DebugColorParams_h
#define HEADER_DebugColorParams_h

#include "NxParametersTypes.h"

#ifndef NX_PARAMETERIZED_ONLY_LAYOUTS
#include "NxParameterized.h"
#include "NxParameters.h"
#include "NxParameterizedTraits.h"
#include "NxTraitsInternal.h"
#endif

namespace physx
{
namespace apex
{

#pragma warning(push)
#pragma warning(disable: 4324) // structure was padded due to __declspec(align())

namespace DebugColorParamsNS
{



struct ParametersStruct
{

	physx::PxU32 Default;
	physx::PxU32 PoseArrows;
	physx::PxU32 MeshStatic;
	physx::PxU32 MeshDynamic;
	physx::PxU32 Shape;
	physx::PxU32 Text0;
	physx::PxU32 Text1;
	physx::PxU32 ForceArrowsLow;
	physx::PxU32 ForceArrowsNorm;
	physx::PxU32 ForceArrowsHigh;
	physx::PxU32 Color0;
	physx::PxU32 Color1;
	physx::PxU32 Color2;
	physx::PxU32 Color3;
	physx::PxU32 Color4;
	physx::PxU32 Color5;
	physx::PxU32 Red;
	physx::PxU32 Green;
	physx::PxU32 Blue;
	physx::PxU32 DarkRed;
	physx::PxU32 DarkGreen;
	physx::PxU32 DarkBlue;
	physx::PxU32 LightRed;
	physx::PxU32 LightGreen;
	physx::PxU32 LightBlue;
	physx::PxU32 Purple;
	physx::PxU32 DarkPurple;
	physx::PxU32 Yellow;
	physx::PxU32 Orange;
	physx::PxU32 Gold;
	physx::PxU32 Emerald;
	physx::PxU32 White;
	physx::PxU32 Black;
	physx::PxU32 Gray;
	physx::PxU32 LightGray;
	physx::PxU32 DarkGray;

};

static const physx::PxU32 checksum[] = { 0x21b30efd, 0xaea10022, 0x72a4df62, 0x8fab217f, };

} // namespace DebugColorParamsNS

#ifndef NX_PARAMETERIZED_ONLY_LAYOUTS
class DebugColorParams : public NxParameterized::NxParameters, public DebugColorParamsNS::ParametersStruct
{
public:
	DebugColorParams(NxParameterized::Traits* traits, void* buf = 0, PxI32* refCount = 0);

	virtual ~DebugColorParams();

	virtual void destroy();

	static const char* staticClassName(void)
	{
		return("DebugColorParams");
	}

	const char* className(void) const
	{
		return(staticClassName());
	}

	static const physx::PxU32 ClassVersion = ((physx::PxU32)0 << 16) + (physx::PxU32)0;

	static physx::PxU32 staticVersion(void)
	{
		return ClassVersion;
	}

	physx::PxU32 version(void) const
	{
		return(staticVersion());
	}

	static const physx::PxU32 ClassAlignment = 8;

	static const physx::PxU32* staticChecksum(physx::PxU32& bits)
	{
		bits = 8 * sizeof(DebugColorParamsNS::checksum);
		return DebugColorParamsNS::checksum;
	}

	static void freeParameterDefinitionTable(NxParameterized::Traits* traits);

	const physx::PxU32* checksum(physx::PxU32& bits) const
	{
		return staticChecksum(bits);
	}

	const DebugColorParamsNS::ParametersStruct& parameters(void) const
	{
		DebugColorParams* tmpThis = const_cast<DebugColorParams*>(this);
		return *(static_cast<DebugColorParamsNS::ParametersStruct*>(tmpThis));
	}

	DebugColorParamsNS::ParametersStruct& parameters(void)
	{
		return *(static_cast<DebugColorParamsNS::ParametersStruct*>(this));
	}

	virtual NxParameterized::ErrorType getParameterHandle(const char* long_name, NxParameterized::Handle& handle) const;
	virtual NxParameterized::ErrorType getParameterHandle(const char* long_name, NxParameterized::Handle& handle);

	void initDefaults(void);

protected:

	virtual const NxParameterized::DefinitionImpl* getParameterDefinitionTree(void);
	virtual const NxParameterized::DefinitionImpl* getParameterDefinitionTree(void) const;


	virtual void getVarPtr(const NxParameterized::Handle& handle, void*& ptr, size_t& offset) const;

private:

	void buildTree(void);
	void initDynamicArrays(void);
	void initStrings(void);
	void initReferences(void);
	void freeDynamicArrays(void);
	void freeStrings(void);
	void freeReferences(void);

	static bool mBuiltFlag;
	static NxParameterized::MutexType mBuiltFlagMutex;
};

class DebugColorParamsFactory : public NxParameterized::Factory
{
	static const char* const vptr;

public:
	virtual NxParameterized::Interface* create(NxParameterized::Traits* paramTraits)
	{
		// placement new on this class using mParameterizedTraits

		void* newPtr = paramTraits->alloc(sizeof(DebugColorParams), DebugColorParams::ClassAlignment);
		if (!NxParameterized::IsAligned(newPtr, DebugColorParams::ClassAlignment))
		{
			NX_PARAM_TRAITS_WARNING(paramTraits, "Unaligned memory allocation for class DebugColorParams");
			paramTraits->free(newPtr);
			return 0;
		}

		memset(newPtr, 0, sizeof(DebugColorParams)); // always initialize memory allocated to zero for default values
		return NX_PARAM_PLACEMENT_NEW(newPtr, DebugColorParams)(paramTraits);
	}

	virtual NxParameterized::Interface* finish(NxParameterized::Traits* paramTraits, void* bufObj, void* bufStart, physx::PxI32* refCount)
	{
		if (!NxParameterized::IsAligned(bufObj, DebugColorParams::ClassAlignment)
		        || !NxParameterized::IsAligned(bufStart, DebugColorParams::ClassAlignment))
		{
			NX_PARAM_TRAITS_WARNING(paramTraits, "Unaligned memory allocation for class DebugColorParams");
			return 0;
		}

		// Init NxParameters-part
		// We used to call empty constructor of DebugColorParams here
		// but it may call default constructors of members and spoil the data
		NX_PARAM_PLACEMENT_NEW(bufObj, NxParameterized::NxParameters)(paramTraits, bufStart, refCount);

		// Init vtable (everything else is already initialized)
		*(const char**)bufObj = vptr;

		return (DebugColorParams*)bufObj;
	}

	virtual const char* getClassName()
	{
		return (DebugColorParams::staticClassName());
	}

	virtual physx::PxU32 getVersion()
	{
		return (DebugColorParams::staticVersion());
	}

	virtual physx::PxU32 getAlignment()
	{
		return (DebugColorParams::ClassAlignment);
	}

	virtual const physx::PxU32* getChecksum(physx::PxU32& bits)
	{
		return (DebugColorParams::staticChecksum(bits));
	}
};
#endif // NX_PARAMETERIZED_ONLY_LAYOUTS

} // namespace apex
} // namespace physx

#pragma warning(pop)

#endif