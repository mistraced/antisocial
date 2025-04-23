#pragma once

typedef struct il2cpp_class il2cpp_class;
typedef struct il2cpp_type il2cpp_type;
typedef struct event_info event_info;
typedef struct method_info method_info;
typedef struct field_info field_info;
typedef struct property_info property_info;
typedef struct il2cpp_assembly il2cpp_assembly;
typedef struct il2cpp_array il2cpp_array;
typedef struct il2cpp_delegate il2cpp_delegate;
typedef struct il2cpp_domain il2cpp_domain;
typedef struct il2cpp_image il2cpp_image;
typedef struct il2cpp_exception il2cpp_exception;
typedef struct il2cpp_profiler il2cpp_profiler;
typedef struct il2cpp_object il2cpp_object;
typedef struct il2cpp_reflection_method il2cpp_reflection_method;
typedef struct il2cpp_reflection_type il2cpp_reflection_type;
typedef struct il2cpp_string il2cpp_string;
typedef struct il2cpp_thread il2cpp_thread;
typedef struct il2cpp_async_result il2cpp_async_result;
typedef struct il2cpp_managed_memory_snapshot il2cpp_managed_memory_snapshot;
typedef struct il2cpp_custom_attr_info il2cpp_custom_attr_info;
typedef enum
{
    IL2CPP_PROFILE_NONE = 0,
    IL2CPP_PROFILE_APPDOMAIN_EVENTS = 1 << 0,
    IL2CPP_PROFILE_ASSEMBLY_EVENTS = 1 << 1,
    IL2CPP_PROFILE_MODULE_EVENTS = 1 << 2,
    IL2CPP_PROFILE_CLASS_EVENTS = 1 << 3,
    IL2CPP_PROFILE_JIT_COMPILATION = 1 << 4,
    IL2CPP_PROFILE_INLINING = 1 << 5,
    IL2CPP_PROFILE_EXCEPTIONS = 1 << 6,
    IL2CPP_PROFILE_ALLOCATIONS = 1 << 7,
    IL2CPP_PROFILE_GC = 1 << 8,
    IL2CPP_PROFILE_THREADS = 1 << 9,
    IL2CPP_PROFILE_REMOTING = 1 << 10,
    IL2CPP_PROFILE_TRANSITIONS = 1 << 11,
    IL2CPP_PROFILE_ENTER_LEAVE = 1 << 12,
    IL2CPP_PROFILE_COVERAGE = 1 << 13,
    IL2CPP_PROFILE_INS_COVERAGE = 1 << 14,
    IL2CPP_PROFILE_STATISTICAL = 1 << 15,
    IL2CPP_PROFILE_METHOD_EVENTS = 1 << 16,
    IL2CPP_PROFILE_MONITOR_EVENTS = 1 << 17,
    IL2CPP_PROFILE_IOMAP_EVENTS = 1 << 18,
    IL2CPP_PROFILE_GC_MOVES = 1 << 19,
    IL2CPP_PROFILE_FILEIO = 1 << 20
} Il2CppProfileFlags;
typedef enum
{
    IL2CPP_PROFILE_FILEIO_WRITE = 0,
    IL2CPP_PROFILE_FILEIO_READ
} Il2CppProfileFileIOKind;
typedef enum
{
    IL2CPP_GC_EVENT_START,
    IL2CPP_GC_EVENT_MARK_START,
    IL2CPP_GC_EVENT_MARK_END,
    IL2CPP_GC_EVENT_RECLAIM_START,
    IL2CPP_GC_EVENT_RECLAIM_END,
    IL2CPP_GC_EVENT_END,
    IL2CPP_GC_EVENT_PRE_STOP_WORLD,
    IL2CPP_GC_EVENT_POST_STOP_WORLD,
    IL2CPP_GC_EVENT_PRE_START_WORLD,
    IL2CPP_GC_EVENT_POST_START_WORLD
} Il2CppGCEvent;
typedef enum
{
    IL2CPP_STAT_NEW_OBJECT_COUNT,
    IL2CPP_STAT_INITIALIZED_CLASS_COUNT,
    IL2CPP_STAT_METHOD_COUNT,
    IL2CPP_STAT_CLASS_STATIC_DATA_SIZE,
    IL2CPP_STAT_GENERIC_INSTANCE_COUNT,
    IL2CPP_STAT_GENERIC_CLASS_COUNT,
    IL2CPP_STAT_INFLATED_METHOD_COUNT,
    IL2CPP_STAT_INFLATED_TYPE_COUNT,
} Il2CppStat;
typedef enum
{
    IL2CPP_UNHANDLED_POLICY_LEGACY,
    IL2CPP_UNHANDLED_POLICY_CURRENT
} Il2CppRuntimeUnhandledExceptionPolicy;
typedef struct Il2CppStackFrameInfo
{
    const method_info* method;
} Il2CppStackFrameInfo;
typedef void ( *Il2CppMethodPointer )( );
typedef struct Il2CppMethodDebugInfo
{
    Il2CppMethodPointer method_pointer;
    int32_t code_size;
    const char* file;
} Il2CppMethodDebugInfo;
typedef struct
{
    void* ( *malloc_func )( size_t size );
    void* ( *aligned_malloc_func )( size_t size, size_t alignment );
    void ( *free_func )( void* ptr );
    void ( *aligned_free_func )( void* ptr );
    void* ( *calloc_func )( size_t nmemb, size_t size );
    void* ( *realloc_func )( void* ptr, size_t size );
    void* ( *aligned_realloc_func )( void* ptr, size_t size, size_t alignment );
} Il2CppMemoryCallbacks;
typedef struct
{
    const char* name;
    void ( *connect )( const char* address );
    int ( *wait_for_attach )( void );
    void ( *close1 )( void );
    void ( *close2 )( void );
    int ( *send )( void* buf, int len );
    int ( *recv )( void* buf, int len );
} Il2CppDebuggerTransport;
#if _MSC_VER
typedef wchar_t Il2CppChar;
#elif __has_feature( cxx_unicode_literals )
typedef char16_t Il2CppChar;
#else
typedef uint16_t Il2CppChar;
#endif
typedef char Il2CppNativeChar;
typedef void ( *il2cpp_register_object_callback )( il2cpp_object** arr, int size, void* userdata );
typedef void ( *il2cpp_WorldChangedCallback )( );
typedef void ( *Il2CppFrameWalkFunc )( const Il2CppStackFrameInfo* info, void* user_data );
typedef void ( *Il2CppProfileFunc )( il2cpp_profiler* prof );
typedef void ( *Il2CppProfileMethodFunc )( il2cpp_profiler* prof, const method_info* method );
typedef void ( *Il2CppProfileAllocFunc )( il2cpp_profiler* prof, il2cpp_object* obj, il2cpp_class* klass );
typedef void ( *Il2CppProfileGCFunc )( il2cpp_profiler* prof, Il2CppGCEvent event, int generation );
typedef void ( *Il2CppProfileGCResizeFunc )( il2cpp_profiler* prof, int64_t new_size );
typedef void ( *Il2CppProfileFileIOFunc )( il2cpp_profiler* prof, Il2CppProfileFileIOKind kind, int count );
typedef void ( *Il2CppProfileThreadFunc )( il2cpp_profiler* prof, unsigned long tid );
typedef const Il2CppNativeChar* ( *Il2CppSetFindPlugInCallback )( const Il2CppNativeChar* );
typedef void ( *Il2CppLogCallback )( const char* );
typedef size_t ( *Il2CppBacktraceFunc )( Il2CppMethodPointer* buffer, size_t maxSize );
typedef struct il2cpp_managed_memory_snapshot il2cpp_managed_memory_snapshot;
typedef uintptr_t il2cpp_array_size_t;
typedef void ( *SynchronizationContextCallback )( intptr_t arg );
typedef uint32_t Il2CppMethodSlot;
static const uint32_t kInvalidIl2CppMethodSlot = 65535;
static const int ipv6AddressSize = 16;
typedef int32_t il2cpp_hresult_t;
typedef struct Il2CppMetadataField
{
    uint32_t offset;
    uint32_t typeIndex;
    const char* name;
    uint8_t isStatic;
} Il2CppMetadataField;
typedef enum Il2CppMetadataTypeFlags
{
    il2cpp_kNone = 0,
    kValueType = 1 << 0,
    kArray = 1 << 1,
    kArrayRankMask = 0xFFFF0000
} Il2CppMetadataTypeFlags;
typedef struct Il2CppMetadataType
{
    Il2CppMetadataTypeFlags flags;
    Il2CppMetadataField* fields;
    uint32_t fieldCount;
    uint32_t staticsSize;
    uint8_t* statics;
    uint32_t baseOrElementTypeIndex;
    char* name;
    const char* assemblyName;
    uint64_t typeInfoAddress;
    uint32_t size;
} Il2CppMetadataType;
typedef struct Il2CppMetadataSnapshot
{
    uint32_t typeCount;
    Il2CppMetadataType* types;
} Il2CppMetadataSnapshot;
typedef struct Il2CppManagedMemorySection
{
    uint64_t sectionStartAddress;
    uint32_t sectionSize;
    uint8_t* sectionBytes;
} Il2CppManagedMemorySection;
typedef struct Il2CppManagedHeap
{
    uint32_t sectionCount;
    Il2CppManagedMemorySection* sections;
} Il2CppManagedHeap;
typedef struct Il2CppStacks
{
    uint32_t stackCount;
    Il2CppManagedMemorySection* stacks;
} Il2CppStacks;
typedef struct NativeObject
{
    uint32_t gcHandleIndex;
    uint32_t size;
    uint32_t instanceId;
    uint32_t classId;
    uint32_t referencedNativeObjectIndicesCount;
    uint32_t* referencedNativeObjectIndices;
} NativeObject;
typedef struct Il2CppGCHandles
{
    uint32_t trackedObjectCount;
    uint64_t* pointersToObjects;
} Il2CppGCHandles;
typedef struct Il2CppRuntimeInformation
{
    uint32_t pointerSize;
    uint32_t objectHeaderSize;
    uint32_t arrayHeaderSize;
    uint32_t arrayBoundsOffsetInHeader;
    uint32_t arraySizeOffsetInHeader;
    uint32_t allocationGranularity;
} Il2CppRuntimeInformation;
typedef struct il2cpp_managed_memory_snapshot
{
    Il2CppManagedHeap heap;
    Il2CppStacks stacks;
    Il2CppMetadataSnapshot metadata;
    Il2CppGCHandles gcHandles;
    Il2CppRuntimeInformation runtimeInformation;
    void* additionalUserInformation;
} il2cpp_managed_memory_snapshot;
typedef enum il2cpp_typeEnum
{
    IL2CPP_TYPE_END = 0x00,
    IL2CPP_TYPE_VOID = 0x01,
    IL2CPP_TYPE_BOOLEAN = 0x02,
    IL2CPP_TYPE_CHAR = 0x03,
    IL2CPP_TYPE_I1 = 0x04,
    IL2CPP_TYPE_U1 = 0x05,
    IL2CPP_TYPE_I2 = 0x06,
    IL2CPP_TYPE_U2 = 0x07,
    IL2CPP_TYPE_I4 = 0x08,
    IL2CPP_TYPE_U4 = 0x09,
    IL2CPP_TYPE_I8 = 0x0a,
    IL2CPP_TYPE_U8 = 0x0b,
    IL2CPP_TYPE_R4 = 0x0c,
    IL2CPP_TYPE_R8 = 0x0d,
    IL2CPP_TYPE_STRING = 0x0e,
    IL2CPP_TYPE_PTR = 0x0f,
    IL2CPP_TYPE_BYREF = 0x10,
    IL2CPP_TYPE_VALUETYPE = 0x11,
    IL2CPP_TYPE_CLASS = 0x12,
    IL2CPP_TYPE_VAR = 0x13,
    IL2CPP_TYPE_ARRAY = 0x14,
    IL2CPP_TYPE_GENERICINST = 0x15,
    IL2CPP_TYPE_TYPEDBYREF = 0x16,
    IL2CPP_TYPE_I = 0x18,
    IL2CPP_TYPE_U = 0x19,
    IL2CPP_TYPE_FNPTR = 0x1b,
    IL2CPP_TYPE_OBJECT = 0x1c,
    IL2CPP_TYPE_SZARRAY = 0x1d,
    IL2CPP_TYPE_MVAR = 0x1e,
    IL2CPP_TYPE_CMOD_REQD = 0x1f,
    IL2CPP_TYPE_CMOD_OPT = 0x20,
    IL2CPP_TYPE_INTERNAL = 0x21,
    IL2CPP_TYPE_MODIFIER = 0x40,
    IL2CPP_TYPE_SENTINEL = 0x41,
    IL2CPP_TYPE_PINNED = 0x45,
    IL2CPP_TYPE_ENUM = 0x55
} il2cpp_typeEnum;
typedef enum
{
    IL2CPP_TOKEN_MODULE = 0x00000000,
    IL2CPP_TOKEN_TYPE_REF = 0x01000000,
    IL2CPP_TOKEN_TYPE_DEF = 0x02000000,
    IL2CPP_TOKEN_FIELD_DEF = 0x04000000,
    IL2CPP_TOKEN_METHOD_DEF = 0x06000000,
    IL2CPP_TOKEN_PARAM_DEF = 0x08000000,
    IL2CPP_TOKEN_INTERFACE_IMPL = 0x09000000,
    IL2CPP_TOKEN_MEMBER_REF = 0x0a000000,
    IL2CPP_TOKEN_CUSTOM_ATTRIBUTE = 0x0c000000,
    IL2CPP_TOKEN_PERMISSION = 0x0e000000,
    IL2CPP_TOKEN_SIGNATURE = 0x11000000,
    IL2CPP_TOKEN_EVENT = 0x14000000,
    IL2CPP_TOKEN_PROPERTY = 0x17000000,
    IL2CPP_TOKEN_MODULE_REF = 0x1a000000,
    IL2CPP_TOKEN_TYPE_SPEC = 0x1b000000,
    IL2CPP_TOKEN_ASSEMBLY = 0x20000000,
    IL2CPP_TOKEN_ASSEMBLY_REF = 0x23000000,
    IL2CPP_TOKEN_FILE = 0x26000000,
    IL2CPP_TOKEN_EXPORTED_TYPE = 0x27000000,
    IL2CPP_TOKEN_MANIFEST_RESOURCE = 0x28000000,
    IL2CPP_TOKEN_GENERIC_PARAM = 0x2a000000,
    IL2CPP_TOKEN_METHOD_SPEC = 0x2b000000,
} Il2CppTokenType;
typedef int32_t TypeIndex;
typedef int32_t TypeDefinitionIndex;
typedef int32_t FieldIndex;
typedef int32_t DefaultValueIndex;
typedef int32_t DefaultValueDataIndex;
typedef int32_t CustomAttributeIndex;
typedef int32_t ParameterIndex;
typedef int32_t MethodIndex;
typedef int32_t GenericMethodIndex;
typedef int32_t PropertyIndex;
typedef int32_t EventIndex;
typedef int32_t GenericContainerIndex;
typedef int32_t GenericParameterIndex;
typedef int16_t GenericParameterConstraintIndex;
typedef int32_t NestedTypeIndex;
typedef int32_t InterfacesIndex;
typedef int32_t VTableIndex;
typedef int32_t InterfaceOffsetIndex;
typedef int32_t RGCTXIndex;
typedef int32_t StringIndex;
typedef int32_t StringLiteralIndex;
typedef int32_t GenericInstIndex;
typedef int32_t ImageIndex;
typedef int32_t AssemblyIndex;
typedef int32_t InteropDataIndex;
static const TypeIndex kTypeIndexInvalid = -1;
static const TypeDefinitionIndex kTypeDefinitionIndexInvalid = -1;
static const DefaultValueDataIndex kDefaultValueIndexNull = -1;
static const CustomAttributeIndex kCustomAttributeIndexInvalid = -1;
static const EventIndex kEventIndexInvalid = -1;
static const FieldIndex kFieldIndexInvalid = -1;
static const MethodIndex kMethodIndexInvalid = -1;
static const PropertyIndex kPropertyIndexInvalid = -1;
static const GenericContainerIndex kGenericContainerIndexInvalid = -1;
static const GenericParameterIndex kGenericParameterIndexInvalid = -1;
static const RGCTXIndex kRGCTXIndexInvalid = -1;
static const StringLiteralIndex kStringLiteralIndexInvalid = -1;
static const InteropDataIndex kInteropDataIndexInvalid = -1;
typedef uint32_t EncodedMethodIndex;
typedef enum Il2CppMetadataUsage
{
    kIl2CppMetadataUsageInvalid,
    kIl2CppMetadataUsageTypeInfo,
    kIl2CppMetadataUsageil2cpp_type,
    kIl2CppMetadataUsageMethodDef,
    kIl2CppMetadataUsagefield_info,
    kIl2CppMetadataUsageStringLiteral,
    kIl2CppMetadataUsageMethodRef,
} Il2CppMetadataUsage;
typedef struct il2cpp_image il2cpp_image;
typedef struct il2cpp_type il2cpp_type;
typedef struct il2cpp_typeDefinitionMetadata il2cpp_typeDefinitionMetadata;
typedef union Il2CppRGCTXDefinitionData
{
    int32_t rgctxDataDummy;
    MethodIndex methodIndex;
    TypeIndex typeIndex;
} Il2CppRGCTXDefinitionData;
typedef enum Il2CppRGCTXDataType
{
    IL2CPP_RGCTX_DATA_INVALID,
    IL2CPP_RGCTX_DATA_TYPE,
    IL2CPP_RGCTX_DATA_CLASS,
    IL2CPP_RGCTX_DATA_METHOD,
    IL2CPP_RGCTX_DATA_ARRAY,
} Il2CppRGCTXDataType;
typedef struct Il2CppRGCTXDefinition
{
    Il2CppRGCTXDataType type;
    Il2CppRGCTXDefinitionData data;
} Il2CppRGCTXDefinition;
typedef struct Il2CppInterfaceOffsetPair
{
    TypeIndex interfaceTypeIndex;
    int32_t offset;
} Il2CppInterfaceOffsetPair;
typedef struct il2cpp_typeDefinition
{
    StringIndex nameIndex;
    StringIndex namespaceIndex;
    TypeIndex byvalTypeIndex;
    TypeIndex byrefTypeIndex;
    TypeIndex declaringTypeIndex;
    TypeIndex parentIndex;
    TypeIndex elementTypeIndex;
    GenericContainerIndex genericContainerIndex;
    uint32_t flags;
    FieldIndex fieldStart;
    MethodIndex methodStart;
    EventIndex eventStart;
    PropertyIndex propertyStart;
    NestedTypeIndex nestedTypesStart;
    InterfacesIndex interfacesStart;
    VTableIndex vtableStart;
    InterfacesIndex interfaceOffsetsStart;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint32_t bitfield;
    uint32_t token;
} il2cpp_typeDefinition;
typedef struct Il2CppFieldDefinition
{
    StringIndex nameIndex;
    TypeIndex typeIndex;
    uint32_t token;
} Il2CppFieldDefinition;
typedef struct Il2CppFieldDefaultValue
{
    FieldIndex fieldIndex;
    TypeIndex typeIndex;
    DefaultValueDataIndex dataIndex;
} Il2CppFieldDefaultValue;
typedef struct Il2CppFieldMarshaledSize
{
    FieldIndex fieldIndex;
    TypeIndex typeIndex;
    int32_t size;
} Il2CppFieldMarshaledSize;
typedef struct Il2CppFieldRef
{
    TypeIndex typeIndex;
    FieldIndex fieldIndex;
} Il2CppFieldRef;
typedef struct Il2CppParameterDefinition
{
    StringIndex nameIndex;
    uint32_t token;
    TypeIndex typeIndex;
} Il2CppParameterDefinition;
typedef struct Il2CppParameterDefaultValue
{
    ParameterIndex parameterIndex;
    TypeIndex typeIndex;
    DefaultValueDataIndex dataIndex;
} Il2CppParameterDefaultValue;
typedef struct Il2CppMethodDefinition
{
    StringIndex nameIndex;
    TypeDefinitionIndex declaringType;
    TypeIndex returnType;
    ParameterIndex parameterStart;
    GenericContainerIndex genericContainerIndex;
    uint32_t token;
    uint16_t flags;
    uint16_t iflags;
    uint16_t slot;
    uint16_t parameterCount;
} Il2CppMethodDefinition;
typedef struct Il2CppEventDefinition
{
    StringIndex nameIndex;
    TypeIndex typeIndex;
    MethodIndex add;
    MethodIndex remove;
    MethodIndex raise;
    uint32_t token;
} Il2CppEventDefinition;
typedef struct Il2CppPropertyDefinition
{
    StringIndex nameIndex;
    MethodIndex get;
    MethodIndex set;
    uint32_t attrs;
    uint32_t token;
} Il2CppPropertyDefinition;
typedef struct Il2CppMethodSpec
{
    MethodIndex methodDefinitionIndex;
    GenericInstIndex classIndexIndex;
    GenericInstIndex methodIndexIndex;
} Il2CppMethodSpec;
typedef struct il2cpp_stringLiteral
{
    uint32_t length;
    StringLiteralIndex dataIndex;
} il2cpp_stringLiteral;
typedef struct
{
    MethodIndex methodIndex;
    MethodIndex invokerIndex;
    MethodIndex adjustorThunkIndex;
} Il2CppGenericMethodIndices;
typedef struct Il2CppGenericMethodFunctionsDefinitions
{
    GenericMethodIndex genericMethodIndex;
    Il2CppGenericMethodIndices indices;
} Il2CppGenericMethodFunctionsDefinitions;
static const int kPublicKeyByteLength = 8;
typedef struct il2cpp_assemblyNameDefinition
{
    StringIndex nameIndex;
    StringIndex cultureIndex;
    StringIndex publicKeyIndex;
    uint32_t hash_alg;
    int32_t hash_len;
    uint32_t flags;
    int32_t major;
    int32_t minor;
    int32_t build;
    int32_t revision;
    uint8_t public_key_token[ 8 ];
} il2cpp_assemblyNameDefinition;
typedef struct il2cpp_imageDefinition
{
    StringIndex nameIndex;
    AssemblyIndex assemblyIndex;
    TypeDefinitionIndex typeStart;
    uint32_t typeCount;
    TypeDefinitionIndex exportedTypeStart;
    uint32_t exportedTypeCount;
    MethodIndex entryPointIndex;
    uint32_t token;
    CustomAttributeIndex customAttributeStart;
    uint32_t customAttributeCount;
} il2cpp_imageDefinition;
typedef struct il2cpp_assemblyDefinition
{
    ImageIndex imageIndex;
    uint32_t token;
    int32_t referencedAssemblyStart;
    int32_t referencedAssemblyCount;
    il2cpp_assemblyNameDefinition aname;
} il2cpp_assemblyDefinition;
typedef struct Il2CppMetadataUsageList
{
    uint32_t start;
    uint32_t count;
} Il2CppMetadataUsageList;
typedef struct Il2CppMetadataUsagePair
{
    uint32_t destinationIndex;
    uint32_t encodedSourceIndex;
} Il2CppMetadataUsagePair;
typedef struct Il2CppCustomAttributeTypeRange
{
    uint32_t token;
    int32_t start;
    int32_t count;
} Il2CppCustomAttributeTypeRange;
typedef struct Il2CppRange
{
    int32_t start;
    int32_t length;
} Il2CppRange;
typedef struct Il2CppWindowsRuntimeTypeNamePair
{
    StringIndex nameIndex;
    TypeIndex typeIndex;
} Il2CppWindowsRuntimeTypeNamePair;
#pragma pack( push, p1, 4 )
typedef struct Il2CppGlobalMetadataHeader
{
    int32_t sanity;
    int32_t version;
    int32_t stringLiteralOffset;
    int32_t stringLiteralCount;
    int32_t stringLiteralDataOffset;
    int32_t stringLiteralDataCount;
    int32_t stringOffset;
    int32_t stringCount;
    int32_t eventsOffset;
    int32_t eventsCount;
    int32_t propertiesOffset;
    int32_t propertiesCount;
    int32_t methodsOffset;
    int32_t methodsCount;
    int32_t parameterDefaultValuesOffset;
    int32_t parameterDefaultValuesCount;
    int32_t fieldDefaultValuesOffset;
    int32_t fieldDefaultValuesCount;
    int32_t fieldAndParameterDefaultValueDataOffset;
    int32_t fieldAndParameterDefaultValueDataCount;
    int32_t fieldMarshaledSizesOffset;
    int32_t fieldMarshaledSizesCount;
    int32_t parametersOffset;
    int32_t parametersCount;
    int32_t fieldsOffset;
    int32_t fieldsCount;
    int32_t genericParametersOffset;
    int32_t genericParametersCount;
    int32_t genericParameterConstraintsOffset;
    int32_t genericParameterConstraintsCount;
    int32_t genericContainersOffset;
    int32_t genericContainersCount;
    int32_t nestedTypesOffset;
    int32_t nestedTypesCount;
    int32_t interfacesOffset;
    int32_t interfacesCount;
    int32_t vtableMethodsOffset;
    int32_t vtableMethodsCount;
    int32_t interfaceOffsetsOffset;
    int32_t interfaceOffsetsCount;
    int32_t typeDefinitionsOffset;
    int32_t typeDefinitionsCount;
    int32_t imagesOffset;
    int32_t imagesCount;
    int32_t assembliesOffset;
    int32_t assembliesCount;
    int32_t metadataUsageListsOffset;
    int32_t metadataUsageListsCount;
    int32_t metadataUsagePairsOffset;
    int32_t metadataUsagePairsCount;
    int32_t fieldRefsOffset;
    int32_t fieldRefsCount;
    int32_t referencedAssembliesOffset;
    int32_t referencedAssembliesCount;
    int32_t attributesInfoOffset;
    int32_t attributesInfoCount;
    int32_t attributeTypesOffset;
    int32_t attributeTypesCount;
    int32_t unresolvedVirtualCallParameterTypesOffset;
    int32_t unresolvedVirtualCallParameterTypesCount;
    int32_t unresolvedVirtualCallParameterRangesOffset;
    int32_t unresolvedVirtualCallParameterRangesCount;
    int32_t windowsRuntimeTypeNamesOffset;
    int32_t windowsRuntimeTypeNamesSize;
    int32_t exportedTypeDefinitionsOffset;
    int32_t exportedTypeDefinitionsCount;
} Il2CppGlobalMetadataHeader;
#pragma pack( pop, p1 )
typedef struct il2cpp_class il2cpp_class;
typedef struct method_info method_info;
typedef struct il2cpp_type il2cpp_type;
typedef struct il2cpp_arrayType
{
    const il2cpp_type* etype;
    uint8_t rank;
    uint8_t numsizes;
    uint8_t numlobounds;
    int* sizes;
    int* lobounds;
} il2cpp_arrayType;
typedef struct Il2CppGenericInst
{
    uint32_t type_argc;
    const il2cpp_type** type_argv;
} Il2CppGenericInst;
typedef struct Il2CppGenericContext
{
    const Il2CppGenericInst* class_inst;
    const Il2CppGenericInst* method_inst;
} Il2CppGenericContext;
typedef struct Il2CppGenericParameter
{
    GenericContainerIndex ownerIndex;
    StringIndex nameIndex;
    GenericParameterConstraintIndex constraintsStart;
    int16_t constraintsCount;
    uint16_t num;
    uint16_t flags;
} Il2CppGenericParameter;
typedef struct Il2CppGenericContainer
{
    int32_t ownerIndex;
    int32_t type_argc;
    int32_t is_method;
    GenericParameterIndex genericParameterStart;
} Il2CppGenericContainer;
typedef struct Il2CppGenericClass
{
    TypeDefinitionIndex typeDefinitionIndex;
    Il2CppGenericContext context;
    il2cpp_class* cached_class;
} Il2CppGenericClass;
typedef struct Il2CppGenericMethod
{
    const method_info* methodDefinition;
    Il2CppGenericContext context;
} Il2CppGenericMethod;
typedef struct il2cpp_type
{
    union
    {
        void* dummy;
        TypeDefinitionIndex klassIndex;
        const il2cpp_type* type;
        il2cpp_arrayType* array;
        GenericParameterIndex genericParameterIndex;
        Il2CppGenericClass* generic_class;
    } data;
    unsigned int attrs : 16;
    il2cpp_typeEnum type : 8;
    unsigned int num_mods : 6;
    unsigned int byref : 1;
    unsigned int pinned : 1;
} il2cpp_type;
typedef enum Il2CppCallConvention
{
    IL2CPP_CALL_DEFAULT,
    IL2CPP_CALL_C,
    IL2CPP_CALL_STDCALL,
    IL2CPP_CALL_THISCALL,
    IL2CPP_CALL_FASTCALL,
    IL2CPP_CALL_VARARG
} Il2CppCallConvention;
typedef enum Il2CppCharSet
{
    CHARSET_ANSI,
    CHARSET_UNICODE,
    CHARSET_NOT_SPECIFIED
} Il2CppCharSet;
typedef struct Il2CppHString__
{
    int unused;
} Il2CppHString__;
typedef Il2CppHString__* Il2CppHString;
typedef struct Il2CppHStringHeader
{
    union
    {
        void* Reserved1;
        char Reserved2[ 24 ];
    } Reserved;
} Il2CppHStringHeader;
typedef struct Il2CppGuid
{
    uint32_t data1;
    uint16_t data2;
    uint16_t data3;
    uint8_t data4[ 8 ];
} Il2CppGuid;
typedef struct Il2CppSafeArrayBound
{
    uint32_t element_count;
    int32_t lower_bound;
} Il2CppSafeArrayBound;
typedef struct Il2CppSafeArray
{
    uint16_t dimension_count;
    uint16_t features;
    uint32_t element_size;
    uint32_t lock_count;
    void* data;
    Il2CppSafeArrayBound bounds[ 1 ];
} Il2CppSafeArray;
typedef struct Il2CppWin32Decimal
{
    uint16_t reserved;
    union
    {
        struct
        {
            uint8_t scale;
            uint8_t sign;
        } s;
        uint16_t signscale;
    } u;
    uint32_t hi32;
    union
    {
        struct
        {
            uint32_t lo32;
            uint32_t mid32;
        } s2;
        uint64_t lo64;
    } u2;
} Il2CppWin32Decimal;
typedef int16_t IL2CPP_VARIANT_BOOL;
typedef enum Il2CppVarType
{
    IL2CPP_VT_EMPTY = 0,
    IL2CPP_VT_NULL = 1,
    IL2CPP_VT_I2 = 2,
    IL2CPP_VT_I4 = 3,
    IL2CPP_VT_R4 = 4,
    IL2CPP_VT_R8 = 5,
    IL2CPP_VT_CY = 6,
    IL2CPP_VT_DATE = 7,
    IL2CPP_VT_BSTR = 8,
    IL2CPP_VT_DISPATCH = 9,
    IL2CPP_VT_ERROR = 10,
    IL2CPP_VT_BOOL = 11,
    IL2CPP_VT_VARIANT = 12,
    IL2CPP_VT_UNKNOWN = 13,
    IL2CPP_VT_DECIMAL = 14,
    IL2CPP_VT_I1 = 16,
    IL2CPP_VT_UI1 = 17,
    IL2CPP_VT_UI2 = 18,
    IL2CPP_VT_UI4 = 19,
    IL2CPP_VT_I8 = 20,
    IL2CPP_VT_UI8 = 21,
    IL2CPP_VT_INT = 22,
    IL2CPP_VT_UINT = 23,
    IL2CPP_VT_VOID = 24,
    IL2CPP_VT_HRESULT = 25,
    IL2CPP_VT_PTR = 26,
    IL2CPP_VT_SAFEARRAY = 27,
    IL2CPP_VT_CARRAY = 28,
    IL2CPP_VT_USERDEFINED = 29,
    IL2CPP_VT_LPSTR = 30,
    IL2CPP_VT_LPWSTR = 31,
    IL2CPP_VT_RECORD = 36,
    IL2CPP_VT_INT_PTR = 37,
    IL2CPP_VT_UINT_PTR = 38,
    IL2CPP_VT_FILETIME = 64,
    IL2CPP_VT_BLOB = 65,
    IL2CPP_VT_STREAM = 66,
    IL2CPP_VT_STORAGE = 67,
    IL2CPP_VT_STREAMED_OBJECT = 68,
    IL2CPP_VT_STORED_OBJECT = 69,
    IL2CPP_VT_BLOB_OBJECT = 70,
    IL2CPP_VT_CF = 71,
    IL2CPP_VT_CLSID = 72,
    IL2CPP_VT_VERSIONED_STREAM = 73,
    IL2CPP_VT_BSTR_BLOB = 0xfff,
    IL2CPP_VT_VECTOR = 0x1000,
    IL2CPP_VT_ARRAY = 0x2000,
    IL2CPP_VT_BYREF = 0x4000,
    IL2CPP_VT_RESERVED = 0x8000,
    IL2CPP_VT_ILLEGAL = 0xffff,
    IL2CPP_VT_ILLEGALMASKED = 0xfff,
    IL2CPP_VT_TYPEMASK = 0xfff,
} Il2CppVarType;
typedef struct Il2CppVariant Il2CppVariant;
typedef struct Il2CppIUnknown Il2CppIUnknown;
typedef struct Il2CppVariant
{
    union
    {
        struct __tagVARIANT
        {
            uint16_t type;
            uint16_t reserved1;
            uint16_t reserved2;
            uint16_t reserved3;
            union
            {
                int64_t llVal;
                int32_t lVal;
                uint8_t bVal;
                int16_t iVal;
                float fltVal;
                double dblVal;
                IL2CPP_VARIANT_BOOL boolVal;
                int32_t scode;
                int64_t cyVal;
                double date;
                Il2CppChar* bstrVal;
                Il2CppIUnknown* punkVal;
                void* pdispVal;
                Il2CppSafeArray* parray;
                uint8_t* pbVal;
                int16_t* piVal;
                int32_t* plVal;
                int64_t* pllVal;
                float* pfltVal;
                double* pdblVal;
                IL2CPP_VARIANT_BOOL* pboolVal;
                int32_t* pscode;
                int64_t* pcyVal;
                double* pdate;
                Il2CppChar* pbstrVal;
                Il2CppIUnknown** ppunkVal;
                void** ppdispVal;
                Il2CppSafeArray** pparray;
                struct Il2CppVariant* pvarVal;
                void* byref;
                char cVal;
                uint16_t uiVal;
                uint32_t ulVal;
                uint64_t ullVal;
                int intVal;
                unsigned int uintVal;
                Il2CppWin32Decimal* pdecVal;
                char* pcVal;
                uint16_t* puiVal;
                uint32_t* pulVal;
                uint64_t* pullVal;
                int* pintVal;
                unsigned int* puintVal;
                struct __tagBRECORD
                {
                    void* pvRecord;
                    void* pRecInfo;
                } n4;
            } n3;
        } n2;
        Il2CppWin32Decimal decVal;
    } n1;
} Il2CppVariant;
typedef struct Il2CppFileTime
{
    uint32_t low;
    uint32_t high;
} Il2CppFileTime;
typedef struct Il2CppStatStg
{
    Il2CppChar* name;
    uint32_t type;
    uint64_t size;
    Il2CppFileTime mtime;
    Il2CppFileTime ctime;
    Il2CppFileTime atime;
    uint32_t mode;
    uint32_t locks;
    Il2CppGuid clsid;
    uint32_t state;
    uint32_t reserved;
} Il2CppStatStg;
typedef enum Il2CppWindowsRuntimeTypeKind
{
    kTypeKindPrimitive = 0,
    kTypeKindMetadata,
    kTypeKindCustom
} Il2CppWindowsRuntimeTypeKind;
typedef struct Il2CppWindowsRuntimeTypeName
{
    Il2CppHString typeName;
    enum Il2CppWindowsRuntimeTypeKind typeKind;
} Il2CppWindowsRuntimeTypeName;
typedef void ( *PInvokeMarshalToNativeFunc )( void* managedStructure, void* marshaledStructure );
typedef void ( *PInvokeMarshalFromNativeFunc )( void* marshaledStructure, void* managedStructure );
typedef void ( *PInvokeMarshalCleanupFunc )( void* marshaledStructure );
typedef struct Il2CppIUnknown* ( *CreateCCWFunc )( il2cpp_object* obj );
typedef struct Il2CppInteropData
{
    Il2CppMethodPointer delegatePInvokeWrapperFunction;
    PInvokeMarshalToNativeFunc pinvokeMarshalToNativeFunction;
    PInvokeMarshalFromNativeFunc pinvokeMarshalFromNativeFunction;
    PInvokeMarshalCleanupFunc pinvokeMarshalCleanupFunction;
    CreateCCWFunc createCCWFunction;
    const Il2CppGuid* guid;
    const il2cpp_type* type;
} Il2CppInteropData;
typedef struct Il2CppInteropData Il2CppInteropData;
typedef struct il2cpp_class il2cpp_class;
typedef struct Il2CppGuid Il2CppGuid;
typedef struct il2cpp_image il2cpp_image;
typedef struct Il2CppAppDomain Il2CppAppDomain;
typedef struct Il2CppAppDomainSetup Il2CppAppDomainSetup;
typedef struct il2cpp_delegate il2cpp_delegate;
typedef struct Il2CppAppContext Il2CppAppContext;
typedef struct Il2CppNameToTypeDefinitionIndexHashTable Il2CppNameToTypeDefinitionIndexHashTable;
typedef struct Il2CppCodeGenModule Il2CppCodeGenModule;
typedef struct VirtualInvokeData
{
    Il2CppMethodPointer methodPtr;
    const method_info* method;
} VirtualInvokeData;
typedef enum il2cpp_typeNameFormat
{
    IL2CPP_TYPE_NAME_FORMAT_IL,
    IL2CPP_TYPE_NAME_FORMAT_REFLECTION,
    IL2CPP_TYPE_NAME_FORMAT_FULL_NAME,
    IL2CPP_TYPE_NAME_FORMAT_ASSEMBLY_QUALIFIED
} il2cpp_typeNameFormat;
typedef struct Il2CppDefaults
{
    il2cpp_image* corlib;
    il2cpp_class* object_class;
    il2cpp_class* byte_class;
    il2cpp_class* void_class;
    il2cpp_class* boolean_class;
    il2cpp_class* sbyte_class;
    il2cpp_class* int16_class;
    il2cpp_class* uint16_class;
    il2cpp_class* int32_class;
    il2cpp_class* uint32_class;
    il2cpp_class* int_class;
    il2cpp_class* uint_class;
    il2cpp_class* int64_class;
    il2cpp_class* uint64_class;
    il2cpp_class* single_class;
    il2cpp_class* double_class;
    il2cpp_class* char_class;
    il2cpp_class* string_class;
    il2cpp_class* enum_class;
    il2cpp_class* array_class;
    il2cpp_class* delegate_class;
    il2cpp_class* multicastdelegate_class;
    il2cpp_class* asyncresult_class;
    il2cpp_class* manualresetevent_class;
    il2cpp_class* typehandle_class;
    il2cpp_class* fieldhandle_class;
    il2cpp_class* methodhandle_class;
    il2cpp_class* systemtype_class;
    il2cpp_class* monotype_class;
    il2cpp_class* exception_class;
    il2cpp_class* threadabortexception_class;
    il2cpp_class* thread_class;
    il2cpp_class* internal_thread_class;
    il2cpp_class* appdomain_class;
    il2cpp_class* appdomain_setup_class;
    il2cpp_class* field_info_class;
    il2cpp_class* method_info_class;
    il2cpp_class* property_info_class;
    il2cpp_class* event_info_class;
    il2cpp_class* mono_event_info_class;
    il2cpp_class* stringbuilder_class;
    il2cpp_class* stack_frame_class;
    il2cpp_class* stack_trace_class;
    il2cpp_class* marshal_class;
    il2cpp_class* typed_reference_class;
    il2cpp_class* marshalbyrefobject_class;
    il2cpp_class* generic_ilist_class;
    il2cpp_class* generic_icollection_class;
    il2cpp_class* generic_ienumerable_class;
    il2cpp_class* generic_ireadonlylist_class;
    il2cpp_class* generic_ireadonlycollection_class;
    il2cpp_class* runtimetype_class;
    il2cpp_class* generic_nullable_class;
    il2cpp_class* il2cpp_com_object_class;
    il2cpp_class* attribute_class;
    il2cpp_class* customattribute_data_class;
    il2cpp_class* version;
    il2cpp_class* culture_info;
    il2cpp_class* async_call_class;
    il2cpp_class* assembly_class;
    il2cpp_class* mono_assembly_class;
    il2cpp_class* assembly_name_class;
    il2cpp_class* mono_field_class;
    il2cpp_class* mono_method_class;
    il2cpp_class* mono_method_info_class;
    il2cpp_class* mono_property_info_class;
    il2cpp_class* parameter_info_class;
    il2cpp_class* mono_parameter_info_class;
    il2cpp_class* module_class;
    il2cpp_class* pointer_class;
    il2cpp_class* system_exception_class;
    il2cpp_class* argument_exception_class;
    il2cpp_class* wait_handle_class;
    il2cpp_class* safe_handle_class;
    il2cpp_class* sort_key_class;
    il2cpp_class* dbnull_class;
    il2cpp_class* error_wrapper_class;
    il2cpp_class* missing_class;
    il2cpp_class* value_type_class;
    il2cpp_class* threadpool_wait_callback_class;
    method_info* threadpool_perform_wait_callback_method;
    il2cpp_class* mono_method_message_class;
    il2cpp_class* ireference_class;
    il2cpp_class* ireferencearray_class;
    il2cpp_class* ikey_value_pair_class;
    il2cpp_class* key_value_pair_class;
    il2cpp_class* windows_foundation_uri_class;
    il2cpp_class* windows_foundation_iuri_runtime_class_class;
    il2cpp_class* system_uri_class;
    il2cpp_class* system_guid_class;
    il2cpp_class* sbyte_shared_enum;
    il2cpp_class* int16_shared_enum;
    il2cpp_class* int32_shared_enum;
    il2cpp_class* int64_shared_enum;
    il2cpp_class* byte_shared_enum;
    il2cpp_class* uint16_shared_enum;
    il2cpp_class* uint32_shared_enum;
    il2cpp_class* uint64_shared_enum;
} Il2CppDefaults;
extern Il2CppDefaults il2cpp_defaults;
typedef struct il2cpp_class il2cpp_class;
typedef struct method_info method_info;
typedef struct field_info field_info;
typedef struct il2cpp_object il2cpp_object;
typedef struct MemberInfo MemberInfo;
typedef struct CustomAttributesCache
{
    int count;
    il2cpp_object** attributes;
} CustomAttributesCache;
typedef void ( *CustomAttributesCacheGenerator )( CustomAttributesCache* );
typedef struct field_info
{
    const char* name;
    const il2cpp_type* type;
    il2cpp_class* parent;
    int32_t offset;
    uint32_t token;
} field_info;
typedef struct property_info
{
    il2cpp_class* parent;
    const char* name;
    const method_info* get;
    const method_info* set;
    uint32_t attrs;
    uint32_t token;
} property_info;
typedef struct event_info
{
    const char* name;
    const il2cpp_type* eventType;
    il2cpp_class* parent;
    const method_info* add;
    const method_info* remove;
    const method_info* raise;
    uint32_t token;
} event_info;
typedef struct ParameterInfo
{
    const char* name;
    int32_t position;
    uint32_t token;
    const il2cpp_type* parameter_type;
} ParameterInfo;
typedef void* ( *InvokerMethod )( Il2CppMethodPointer, const method_info*, void*, void** );
typedef enum MethodVariableKind
{
    kMethodVariableKind_This,
    kMethodVariableKind_Parameter,
    kMethodVariableKind_LocalVariable
} MethodVariableKind;
typedef enum SequencePointKind
{
    kSequencePointKind_Normal,
    kSequencePointKind_StepOut
} SequencePointKind;
typedef struct Il2CppMethodExecutionContextInfo
{
    TypeIndex typeIndex;
    int32_t nameIndex;
    int32_t scopeIndex;
} Il2CppMethodExecutionContextInfo;
typedef struct Il2CppMethodExecutionContextInfoIndex
{
    int32_t startIndex;
    int32_t count;
} Il2CppMethodExecutionContextInfoIndex;
typedef struct Il2CppMethodScope
{
    int32_t startOffset;
    int32_t endOffset;
} Il2CppMethodScope;
typedef struct Il2CppMethodHeaderInfo
{
    int32_t code_size;
    int32_t startScope;
    int32_t numScopes;
} Il2CppMethodHeaderInfo;
typedef struct Il2CppSequencePointSourceFile
{
    const char* file;
    uint8_t hash[ 16 ];
} Il2CppSequencePointSourceFile;
typedef struct il2cpp_typeSourceFilePair
{
    TypeDefinitionIndex klassIndex;
    int32_t sourceFileIndex;
} il2cpp_typeSourceFilePair;
typedef struct Il2CppSequencePoint
{
    MethodIndex methodDefinitionIndex;
    int32_t sourceFileIndex;
    int32_t lineStart, lineEnd;
    int32_t columnStart, columnEnd;
    int32_t ilOffset;
    SequencePointKind kind;
    int32_t isActive;
    int32_t id;
} Il2CppSequencePoint;
typedef struct Il2CppCatchPoint
{
    MethodIndex methodDefinitionIndex;
    TypeIndex catchTypeIndex;
    int32_t ilOffset;
    int32_t tryId;
    int32_t parentTryId;
} Il2CppCatchPoint;
typedef struct Il2CppDebuggerMetadataRegistration
{
    Il2CppMethodExecutionContextInfo* methodExecutionContextInfos;
    Il2CppMethodExecutionContextInfoIndex* methodExecutionContextInfoIndexes;
    Il2CppMethodScope* methodScopes;
    Il2CppMethodHeaderInfo* methodHeaderInfos;
    Il2CppSequencePointSourceFile* sequencePointSourceFiles;
    int32_t numSequencePoints;
    Il2CppSequencePoint* sequencePoints;
    int32_t numCatchPoints;
    Il2CppCatchPoint* catchPoints;
    int32_t numTypeSourceFileEntries;
    il2cpp_typeSourceFilePair* typeSourceFiles;
    const char** methodExecutionContextInfoStrings;
} Il2CppDebuggerMetadataRegistration;
typedef union Il2CppRGCTXData
{
    void* rgctxDataDummy;
    const method_info* method;
    const il2cpp_type* type;
    il2cpp_class* klass;
} Il2CppRGCTXData;
typedef struct method_info
{
    Il2CppMethodPointer method_pointer;
    InvokerMethod invoker_method;
    const char* name;
    il2cpp_class* klass;
    const il2cpp_type* return_type;
    const ParameterInfo* parameters;
    union
    {
        const Il2CppRGCTXData* rgctx_data;
        const Il2CppMethodDefinition* methodDefinition;
    };
    union
    {
        const Il2CppGenericMethod* genericMethod;
        const Il2CppGenericContainer* genericContainer;
        Il2CppMethodPointer nativeFunction;
    };
    uint32_t token;
    uint16_t flags;
    uint16_t iflags;
    uint16_t slot;
    uint8_t parameters_count;
    uint8_t is_generic : 1;
    uint8_t is_inflated : 1;
    uint8_t wrapper_type : 1;
    uint8_t is_marshaled_from_native : 1;
} method_info;
typedef struct Il2CppRuntimeInterfaceOffsetPair
{
    il2cpp_class* interfaceType;
    int32_t offset;
} Il2CppRuntimeInterfaceOffsetPair;
typedef struct il2cpp_class
{
    const il2cpp_image* image;
    void* gc_desc;
    const char* name;
    const char* namespaze;
    il2cpp_type byval_arg;
    il2cpp_type this_arg;
    il2cpp_class* element_class;
    il2cpp_class* castClass;
    il2cpp_class* declaringType;
    il2cpp_class* parent;
    Il2CppGenericClass* generic_class;
    const il2cpp_typeDefinition* typeDefinition;
    const Il2CppInteropData* interopData;
    il2cpp_class* klass;
    field_info* fields;
    const event_info* events;
    const property_info* properties;
    const method_info** methods;
    il2cpp_class** nestedTypes;
    il2cpp_class** implementedInterfaces;
    Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
    void* static_fields;
    const Il2CppRGCTXData* rgctx_data;
    struct il2cpp_class** typeHierarchy;
    void* unity_user_data;
    uint32_t initializationExceptionGCHandle;
    uint32_t cctor_started;
    uint32_t cctor_finished;
    __attribute__( ( aligned( 8 ) ) ) size_t cctor_thread;
    GenericContainerIndex genericContainerIndex;
    uint32_t instance_size;
    uint32_t actualSize;
    uint32_t element_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
    int32_t thread_static_fields_offset;
    uint32_t flags;
    uint32_t token;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint8_t typeHierarchyDepth;
    uint8_t genericRecursionDepth;
    uint8_t rank;
    uint8_t minimumAlignment;
    uint8_t naturalAligment;
    uint8_t packingSize;
    uint8_t initialized_and_no_error : 1;
    uint8_t valuetype : 1;
    uint8_t initialized : 1;
    uint8_t enumtype : 1;
    uint8_t is_generic : 1;
    uint8_t has_references : 1;
    uint8_t init_pending : 1;
    uint8_t size_inited : 1;
    uint8_t has_finalize : 1;
    uint8_t has_cctor : 1;
    uint8_t is_blittable : 1;
    uint8_t is_import_or_windows_runtime : 1;
    uint8_t is_vtable_initialized : 1;
    uint8_t has_initialization_error : 1;
    VirtualInvokeData vtable[ 32 ];
} il2cpp_class;

typedef struct il2cpp_class_0
{
    const il2cpp_image* image;
    void* gc_desc;
    const char* name;
    const char* namespaze;
    il2cpp_type byval_arg;
    il2cpp_type this_arg;
    il2cpp_class* element_class;
    il2cpp_class* castClass;
    il2cpp_class* declaringType;
    il2cpp_class* parent;
    Il2CppGenericClass* generic_class;
    const il2cpp_typeDefinition* typeDefinition;
    const Il2CppInteropData* interopData;
    il2cpp_class* klass;
    field_info* fields;
    const event_info* events;
    const property_info* properties;
    const method_info** methods;
    il2cpp_class** nestedTypes;
    il2cpp_class** implementedInterfaces;
} il2cpp_class_0;

typedef struct il2cpp_class_1
{
    struct il2cpp_class** typeHierarchy;
    void* unity_user_data;
    uint32_t initializationExceptionGCHandle;
    uint32_t cctor_started;
    uint32_t cctor_finished;
#ifdef IS_32BIT
    uint32_t cctor_thread;
#else
    __attribute__( ( aligned( 8 ) ) ) size_t cctor_thread;
#endif
    GenericContainerIndex genericContainerIndex;
    uint32_t instance_size;
    uint32_t actualSize;
    uint32_t element_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
    int32_t thread_static_fields_offset;
    uint32_t flags;
    uint32_t token;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint8_t typeHierarchyDepth;
    uint8_t genericRecursionDepth;
    uint8_t rank;
    uint8_t minimumAlignment;
    uint8_t naturalAligment;
    uint8_t packingSize;
    uint8_t initialized_and_no_error : 1;
    uint8_t valuetype : 1;
    uint8_t initialized : 1;
    uint8_t enumtype : 1;
    uint8_t is_generic : 1;
    uint8_t has_references : 1;
    uint8_t init_pending : 1;
    uint8_t size_inited : 1;
    uint8_t has_finalize : 1;
    uint8_t has_cctor : 1;
    uint8_t is_blittable : 1;
    uint8_t is_import_or_windows_runtime : 1;
    uint8_t is_vtable_initialized : 1;
    uint8_t has_initialization_error : 1;
} il2cpp_class_1;

typedef struct __attribute__( ( aligned( 8 ) ) ) il2cpp_class_Merged
{
    struct il2cpp_class_0 _0;
    Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
    void* static_fields;
    const Il2CppRGCTXData* rgctx_data;
    struct il2cpp_class_1 _1;
    VirtualInvokeData vtable[ 32 ];
} il2cpp_class_Merged;

typedef struct il2cpp_typeDefinitionSizes
{
    uint32_t instance_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
} il2cpp_typeDefinitionSizes;
typedef struct il2cpp_domain
{
    Il2CppAppDomain* domain;
    Il2CppAppDomainSetup* setup;
    Il2CppAppContext* default_context;
    const char* friendly_name;
    uint32_t domain_id;
    volatile int threadpool_jobs;
    void* agent_info;
} il2cpp_domain;
typedef struct il2cpp_assemblyName
{
    const char* name;
    const char* culture;
    const uint8_t* public_key;
    uint32_t hash_alg;
    int32_t hash_len;
    uint32_t flags;
    int32_t major;
    int32_t minor;
    int32_t build;
    int32_t revision;
    uint8_t public_key_token[ 8 ];
} il2cpp_assemblyName;
typedef struct il2cpp_image
{
    const char* name;
    const char* nameNoExt;
    il2cpp_assembly* assembly;
    TypeDefinitionIndex typeStart;
    uint32_t typeCount;
    TypeDefinitionIndex exportedTypeStart;
    uint32_t exportedTypeCount;
    CustomAttributeIndex customAttributeStart;
    uint32_t customAttributeCount;
    MethodIndex entryPointIndex;
    Il2CppNameToTypeDefinitionIndexHashTable* nameToClassHashTable;
    const Il2CppCodeGenModule* codeGenModule;
    uint32_t token;
    uint8_t dynamic;
} il2cpp_image;
typedef struct il2cpp_assembly
{
    il2cpp_image* image;
    uint32_t token;
    int32_t referencedAssemblyStart;
    int32_t referencedAssemblyCount;
    il2cpp_assemblyName aname;
} il2cpp_assembly;
typedef struct Il2CppCodeGenOptions
{
    uint8_t enablePrimitiveValueTypeGenericSharing;
    int maximumRuntimeGenericDepth;
} Il2CppCodeGenOptions;
typedef struct Il2CppTokenIndexPair
{
    uint32_t token;
    int32_t index;
} Il2CppTokenIndexPair;
typedef struct Il2CppTokenRangePair
{
    uint32_t token;
    Il2CppRange range;
} Il2CppTokenRangePair;
typedef struct Il2CppTokenIndexMethodTuple
{
    uint32_t token;
    int32_t index;
    void** method;
    uint32_t genericMethodIndex;
} Il2CppTokenIndexMethodTuple;
typedef struct Il2CppTokenAdjustorThunkPair
{
    uint32_t token;
    Il2CppMethodPointer adjustorThunk;
} Il2CppTokenAdjustorThunkPair;
typedef struct Il2CppWindowsRuntimeFactoryTableEntry
{
    const il2cpp_type* type;
    Il2CppMethodPointer createFactoryFunction;
} Il2CppWindowsRuntimeFactoryTableEntry;
typedef struct Il2CppCodeGenModule
{
    const char* moduleName;
    const uint32_t method_pointerCount;
    const Il2CppMethodPointer* method_pointers;
    const uint32_t adjustorThunkCount;
    const Il2CppTokenAdjustorThunkPair* adjustorThunks;
    const int32_t* invokerIndices;
    const uint32_t reversePInvokeWrapperCount;
    const Il2CppTokenIndexMethodTuple* reversePInvokeWrapperIndices;
    const uint32_t rgctxRangesCount;
    const Il2CppTokenRangePair* rgctxRanges;
    const uint32_t rgctxsCount;
    const Il2CppRGCTXDefinition* rgctxs;
    const Il2CppDebuggerMetadataRegistration* debuggerMetadata;
} Il2CppCodeGenModule;
typedef struct Il2CppCodeRegistration
{
    uint32_t reversePInvokeWrapperCount;
    const Il2CppMethodPointer* reversePInvokeWrappers;
    uint32_t genericMethodPointersCount;
    const Il2CppMethodPointer* genericMethodPointers;
    const Il2CppMethodPointer* genericAdjustorThunks;
    uint32_t invokerPointersCount;
    const InvokerMethod* invokerPointers;
    CustomAttributeIndex customAttributeCount;
    const CustomAttributesCacheGenerator* customAttributeGenerators;
    uint32_t unresolvedVirtualCallCount;
    const Il2CppMethodPointer* unresolvedVirtualCallPointers;
    uint32_t interopDataCount;
    Il2CppInteropData* interopData;
    uint32_t windowsRuntimeFactoryCount;
    Il2CppWindowsRuntimeFactoryTableEntry* windowsRuntimeFactoryTable;
    uint32_t codeGenModulesCount;
    const Il2CppCodeGenModule** codeGenModules;
} Il2CppCodeRegistration;
typedef struct Il2CppMetadataRegistration
{
    int32_t genericClassesCount;
    Il2CppGenericClass* const* genericClasses;
    int32_t genericInstsCount;
    const Il2CppGenericInst* const* genericInsts;
    int32_t genericMethodTableCount;
    const Il2CppGenericMethodFunctionsDefinitions* genericMethodTable;
    int32_t typesCount;
    const il2cpp_type* const* types;
    int32_t methodSpecsCount;
    const Il2CppMethodSpec* methodSpecs;
    FieldIndex fieldOffsetsCount;
    const int32_t** fieldOffsets;
    TypeDefinitionIndex typeDefinitionsSizesCount;
    const il2cpp_typeDefinitionSizes** typeDefinitionsSizes;
    const size_t metadataUsagesCount;
    void** const* metadataUsages;
} Il2CppMetadataRegistration;
typedef struct Il2CppPerfCounters
{
    uint32_t jit_methods;
    uint32_t jit_bytes;
    uint32_t jit_time;
    uint32_t jit_failures;
    uint32_t exceptions_thrown;
    uint32_t exceptions_filters;
    uint32_t exceptions_finallys;
    uint32_t exceptions_depth;
    uint32_t aspnet_requests_queued;
    uint32_t aspnet_requests;
    uint32_t gc_collections0;
    uint32_t gc_collections1;
    uint32_t gc_collections2;
    uint32_t gc_promotions0;
    uint32_t gc_promotions1;
    uint32_t gc_promotion_finalizers;
    uint32_t gc_gen0size;
    uint32_t gc_gen1size;
    uint32_t gc_gen2size;
    uint32_t gc_lossize;
    uint32_t gc_fin_survivors;
    uint32_t gc_num_handles;
    uint32_t gc_allocated;
    uint32_t gc_induced;
    uint32_t gc_time;
    uint32_t gc_total_bytes;
    uint32_t gc_committed_bytes;
    uint32_t gc_reserved_bytes;
    uint32_t gc_num_pinned;
    uint32_t gc_sync_blocks;
    uint32_t remoting_calls;
    uint32_t remoting_channels;
    uint32_t remoting_proxies;
    uint32_t remoting_classes;
    uint32_t remoting_objects;
    uint32_t remoting_contexts;
    uint32_t loader_classes;
    uint32_t loader_total_classes;
    uint32_t loader_appdomains;
    uint32_t loader_total_appdomains;
    uint32_t loader_assemblies;
    uint32_t loader_total_assemblies;
    uint32_t loader_failures;
    uint32_t loader_bytes;
    uint32_t loader_appdomains_uloaded;
    uint32_t thread_contentions;
    uint32_t thread_queue_len;
    uint32_t thread_queue_max;
    uint32_t thread_num_logical;
    uint32_t thread_num_physical;
    uint32_t thread_cur_recognized;
    uint32_t thread_num_recognized;
    uint32_t interop_num_ccw;
    uint32_t interop_num_stubs;
    uint32_t interop_num_marshals;
    uint32_t security_num_checks;
    uint32_t security_num_link_checks;
    uint32_t security_time;
    uint32_t security_depth;
    uint32_t unused;
    uint64_t threadpool_workitems;
    uint64_t threadpool_ioworkitems;
    unsigned int threadpool_threads;
    unsigned int threadpool_iothreads;
} Il2CppPerfCounters;
typedef struct il2cpp_class il2cpp_class;
typedef struct method_info method_info;
typedef struct property_info property_info;
typedef struct field_info field_info;
typedef struct event_info event_info;
typedef struct il2cpp_type il2cpp_type;
typedef struct il2cpp_assembly il2cpp_assembly;
typedef struct il2cpp_exception il2cpp_exception;
typedef struct il2cpp_image il2cpp_image;
typedef struct il2cpp_domain il2cpp_domain;
typedef struct il2cpp_string il2cpp_string;
typedef struct il2cpp_reflection_method il2cpp_reflection_method;
typedef struct Il2CppAsyncCall Il2CppAsyncCall;
typedef struct Il2CppIUnknown Il2CppIUnknown;
typedef struct Il2CppWaitHandle Il2CppWaitHandle;
typedef struct MonitorData MonitorData;
typedef struct Il2CppReflectionAssembly Il2CppReflectionAssembly;
typedef il2cpp_class Il2CppVTable;
typedef struct il2cpp_object
{
    union
    {
        il2cpp_class* klass;
        Il2CppVTable* vtable;
    };
    MonitorData* monitor;
} il2cpp_object;
typedef int32_t il2cpp_array_lower_bound_t;
typedef struct il2cpp_arrayBounds
{
    il2cpp_array_size_t length;
    il2cpp_array_lower_bound_t lower_bound;
} il2cpp_arrayBounds;
typedef struct il2cpp_array
{
    il2cpp_object obj;
    il2cpp_arrayBounds* bounds;
    il2cpp_array_size_t max_length;
} il2cpp_array;
typedef struct il2cpp_arraySize
{
    il2cpp_object obj;
    il2cpp_arrayBounds* bounds;
    il2cpp_array_size_t max_length;
    __attribute__( ( aligned( 8 ) ) ) void* vector[ 32 ];
} il2cpp_arraySize;
typedef struct il2cpp_string
{
    il2cpp_object object;
    int32_t length;
    Il2CppChar chars[ 32 ];
} il2cpp_string;
typedef struct il2cpp_reflection_type
{
    il2cpp_object object;
    const il2cpp_type* type;
} il2cpp_reflection_type;
typedef struct Il2CppReflectionRuntimeType
{
    il2cpp_reflection_type type;
    il2cpp_object* type_info;
    il2cpp_object* genericCache;
    il2cpp_object* serializationCtor;
} Il2CppReflectionRuntimeType;
typedef struct Il2CppReflectionMonoType
{
    Il2CppReflectionRuntimeType type;
} Il2CppReflectionMonoType;
typedef struct Il2CppReflectionEvent
{
    il2cpp_object object;
    il2cpp_object* cached_add_event;
} Il2CppReflectionEvent;
typedef struct Il2CppReflectionMonoEvent
{
    Il2CppReflectionEvent event;
    il2cpp_reflection_type* reflectedType;
    const event_info* event_info;
} Il2CppReflectionMonoEvent;
typedef struct Il2CppReflectionMonoevent_info
{
    il2cpp_reflection_type* declaringType;
    il2cpp_reflection_type* reflectedType;
    il2cpp_string* name;
    il2cpp_reflection_method* addMethod;
    il2cpp_reflection_method* removeMethod;
    il2cpp_reflection_method* raiseMethod;
    uint32_t eventAttributes;
    il2cpp_array* otherMethods;
} Il2CppReflectionMonoevent_info;
typedef struct Il2CppReflectionField
{
    il2cpp_object object;
    il2cpp_class* klass;
    field_info* field;
    il2cpp_string* name;
    il2cpp_reflection_type* type;
    uint32_t attrs;
} Il2CppReflectionField;
typedef struct Il2CppReflectionProperty
{
    il2cpp_object object;
    il2cpp_class* klass;
    const property_info* property;
} Il2CppReflectionProperty;
typedef struct il2cpp_reflection_method
{
    il2cpp_object object;
    const method_info* method;
    il2cpp_string* name;
    il2cpp_reflection_type* reftype;
} il2cpp_reflection_method;
typedef struct Il2CppReflectionGenericMethod
{
    il2cpp_reflection_method base;
} Il2CppReflectionGenericMethod;
typedef struct Il2Cppmethod_info
{
    il2cpp_reflection_type* parent;
    il2cpp_reflection_type* ret;
    uint32_t attrs;
    uint32_t implattrs;
    uint32_t callconv;
} Il2Cppmethod_info;
typedef struct Il2Cppproperty_info
{
    il2cpp_reflection_type* parent;
    il2cpp_reflection_type* declaringType;
    il2cpp_string* name;
    il2cpp_reflection_method* get;
    il2cpp_reflection_method* set;
    uint32_t attrs;
} Il2Cppproperty_info;
typedef struct Il2CppReflectionParameter
{
    il2cpp_object object;
    il2cpp_reflection_type* ClassImpl;
    il2cpp_object* DefaultValueImpl;
    il2cpp_object* MemberImpl;
    il2cpp_string* NameImpl;
    int32_t PositionImpl;
    uint32_t AttrsImpl;
    il2cpp_object* MarshalAsImpl;
} Il2CppReflectionParameter;
typedef struct Il2CppReflectionModule
{
    il2cpp_object obj;
    const il2cpp_image* image;
    Il2CppReflectionAssembly* assembly;
    il2cpp_string* fqname;
    il2cpp_string* name;
    il2cpp_string* scopename;
    uint8_t is_resource;
    uint32_t token;
} Il2CppReflectionModule;
typedef struct Il2CppReflectionAssemblyName
{
    il2cpp_object obj;
    il2cpp_string* name;
    il2cpp_string* codebase;
    int32_t major, minor, build, revision;
    il2cpp_object* cultureInfo;
    uint32_t flags;
    uint32_t hashalg;
    il2cpp_object* keypair;
    il2cpp_array* publicKey;
    il2cpp_array* keyToken;
    uint32_t versioncompat;
    il2cpp_object* version;
    uint32_t processor_architecture;
    uint32_t contentType;
} Il2CppReflectionAssemblyName;
typedef struct Il2CppReflectionAssembly
{
    il2cpp_object object;
    const il2cpp_assembly* assembly;
    il2cpp_object* resolve_event_holder;
    il2cpp_object* evidence;
    il2cpp_object* minimum;
    il2cpp_object* optional;
    il2cpp_object* refuse;
    il2cpp_object* granted;
    il2cpp_object* denied;
    uint8_t from_byte_array;
    il2cpp_string* name;
} Il2CppReflectionAssembly;
typedef struct Il2CppReflectionMarshal
{
    il2cpp_object object;
    int32_t count;
    int32_t type;
    int32_t eltype;
    il2cpp_string* guid;
    il2cpp_string* mcookie;
    il2cpp_string* marshaltype;
    il2cpp_object* marshaltyperef;
    int32_t param_num;
    uint8_t has_size;
} Il2CppReflectionMarshal;
typedef struct Il2CppReflectionPointer
{
    il2cpp_object object;
    void* data;
    il2cpp_reflection_type* type;
} Il2CppReflectionPointer;
typedef struct Il2CppInternalThread
{
    il2cpp_object obj;
    int lock_thread_id;
    void* handle;
    void* native_handle;
    il2cpp_array* cached_culture_info;
    Il2CppChar* name;
    int name_len;
    uint32_t state;
    il2cpp_object* abort_exc;
    int abort_state_handle;
    uint64_t tid;
    intptr_t debugger_thread;
    void** static_data;
    void* runtime_thread_info;
    il2cpp_object* current_appcontext;
    il2cpp_object* root_domain_thread;
    il2cpp_array* _serialized_principal;
    int _serialized_principal_version;
    void* appdomain_refs;
    int32_t interruption_requested;
    void* synch_cs;
    uint8_t threadpool_thread;
    uint8_t thread_interrupt_requested;
    int stack_size;
    uint8_t apartment_state;
    int critical_region_level;
    int managed_id;
    uint32_t small_id;
    void* manage_callback;
    void* interrupt_on_stop;
    intptr_t flags;
    void* thread_pinning_ref;
    void* abort_protected_block_count;
    int32_t priority;
    void* owned_mutexes;
    void* suspended;
    int32_t self_suspended;
    size_t thread_state;
    size_t unused2;
    void* last;
} Il2CppInternalThread;
typedef struct Il2CppIOSelectorJob
{
    il2cpp_object object;
    int32_t operation;
    il2cpp_object* callback;
    il2cpp_object* state;
} Il2CppIOSelectorJob;
typedef enum
{
    Il2Cpp_CallType_Sync = 0,
    Il2Cpp_CallType_BeginInvoke = 1,
    Il2Cpp_CallType_EndInvoke = 2,
    Il2Cpp_CallType_OneWay = 3
} Il2CppCallType;
typedef struct Il2CppMethodMessage
{
    il2cpp_object obj;
    il2cpp_reflection_method* method;
    il2cpp_array* args;
    il2cpp_array* names;
    il2cpp_array* arg_types;
    il2cpp_object* ctx;
    il2cpp_object* rval;
    il2cpp_object* exc;
    il2cpp_async_result* async_result;
    uint32_t call_type;
} Il2CppMethodMessage;
typedef struct Il2CppAppDomainSetup
{
    il2cpp_object object;
    il2cpp_string* application_base;
    il2cpp_string* application_name;
    il2cpp_string* cache_path;
    il2cpp_string* configuration_file;
    il2cpp_string* dynamic_base;
    il2cpp_string* license_file;
    il2cpp_string* private_bin_path;
    il2cpp_string* private_bin_path_probe;
    il2cpp_string* shadow_copy_directories;
    il2cpp_string* shadow_copy_files;
    uint8_t publisher_policy;
    uint8_t path_changed;
    int loader_optimization;
    uint8_t disallow_binding_redirects;
    uint8_t disallow_code_downloads;
    il2cpp_object* activation_arguments;
    il2cpp_object* domain_initializer;
    il2cpp_object* application_trust;
    il2cpp_array* domain_initializer_args;
    uint8_t disallow_appbase_probe;
    il2cpp_array* configuration_bytes;
    il2cpp_array* serialized_non_primitives;
} Il2CppAppDomainSetup;
typedef struct il2cpp_thread
{
    il2cpp_object obj;
    Il2CppInternalThread* internal_thread;
    il2cpp_object* start_obj;
    il2cpp_exception* pending_exception;
    il2cpp_object* principal;
    int32_t principal_version;
    il2cpp_delegate* delegate;
    il2cpp_object* executionContext;
    uint8_t executionContextBelongsToOuterScope;
} il2cpp_thread;
typedef struct il2cpp_exception
{
    il2cpp_object object;
    il2cpp_string* className;
    il2cpp_string* message;
    il2cpp_object* _data;
    struct il2cpp_exception* inner_ex;
    il2cpp_string* _helpURL;
    il2cpp_array* trace_ips;
    il2cpp_string* stack_trace;
    il2cpp_string* remote_stack_trace;
    int remote_stack_index;
    il2cpp_object* _dynamicMethods;
    il2cpp_hresult_t hresult;
    il2cpp_string* source;
    il2cpp_object* safeSerializationManager;
    il2cpp_array* captured_traces;
    il2cpp_array* native_trace_ips;
} il2cpp_exception;
typedef struct Il2CppSystemException
{
    il2cpp_exception base;
} Il2CppSystemException;
typedef struct Il2CppArgumentException
{
    il2cpp_exception base;
    il2cpp_string* argName;
} Il2CppArgumentException;
typedef struct il2cpp_typedRef
{
    const il2cpp_type* type;
    void* value;
    il2cpp_class* klass;
} il2cpp_typedRef;
typedef struct il2cpp_delegate
{
    il2cpp_object object;
    Il2CppMethodPointer method_ptr;
    InvokerMethod invoke_impl;
    il2cpp_object* target;
    const method_info* method;
    void* delegate_trampoline;
    intptr_t extraArg;
    uint8_t** method_code;
    il2cpp_reflection_method* method_info;
    il2cpp_reflection_method* original_method_info;
    il2cpp_object* data;
    uint8_t method_is_virtual;
} il2cpp_delegate;
typedef struct Il2CppMulticastDelegate
{
    il2cpp_delegate delegate;
    il2cpp_array* delegates;
} Il2CppMulticastDelegate;
typedef struct Il2CppMarshalByRefObject
{
    il2cpp_object obj;
    il2cpp_object* identity;
} Il2CppMarshalByRefObject;
typedef struct Il2CppAppDomain
{
    Il2CppMarshalByRefObject mbr;
    il2cpp_domain* data;
} Il2CppAppDomain;
typedef struct Il2CppStackFrame
{
    il2cpp_object obj;
    int32_t il_offset;
    int32_t native_offset;
    uint64_t methodAddress;
    uint32_t methodIndex;
    il2cpp_reflection_method* method;
    il2cpp_string* filename;
    int32_t line;
    int32_t column;
    il2cpp_string* internal_method_name;
} Il2CppStackFrame;
typedef struct Il2CppDateTimeFormatInfo
{
    il2cpp_object obj;
    il2cpp_object* CultureData;
    il2cpp_string* Name;
    il2cpp_string* LangName;
    il2cpp_object* CompareInfo;
    il2cpp_object* CultureInfo;
    il2cpp_string* AMDesignator;
    il2cpp_string* PMDesignator;
    il2cpp_string* DateSeparator;
    il2cpp_string* GeneralShortTimePattern;
    il2cpp_string* GeneralLongTimePattern;
    il2cpp_string* TimeSeparator;
    il2cpp_string* MonthDayPattern;
    il2cpp_string* DateTimeOffsetPattern;
    il2cpp_object* Calendar;
    uint32_t FirstDayOfWeek;
    uint32_t CalendarWeekRule;
    il2cpp_string* FullDateTimePattern;
    il2cpp_array* AbbreviatedDayNames;
    il2cpp_array* ShortDayNames;
    il2cpp_array* DayNames;
    il2cpp_array* AbbreviatedMonthNames;
    il2cpp_array* MonthNames;
    il2cpp_array* GenitiveMonthNames;
    il2cpp_array* GenitiveAbbreviatedMonthNames;
    il2cpp_array* LeapYearMonthNames;
    il2cpp_string* LongDatePattern;
    il2cpp_string* ShortDatePattern;
    il2cpp_string* YearMonthPattern;
    il2cpp_string* LongTimePattern;
    il2cpp_string* ShortTimePattern;
    il2cpp_array* YearMonthPatterns;
    il2cpp_array* ShortDatePatterns;
    il2cpp_array* LongDatePatterns;
    il2cpp_array* ShortTimePatterns;
    il2cpp_array* LongTimePatterns;
    il2cpp_array* EraNames;
    il2cpp_array* AbbrevEraNames;
    il2cpp_array* AbbrevEnglishEraNames;
    il2cpp_array* OptionalCalendars;
    uint8_t readOnly;
    int32_t FormatFlags;
    int32_t CultureID;
    uint8_t UseUserOverride;
    uint8_t UseCalendarInfo;
    int32_t DataItem;
    uint8_t IsDefaultCalendar;
    il2cpp_array* DateWords;
    il2cpp_string* FullTimeSpanPositivePattern;
    il2cpp_string* FullTimeSpanNegativePattern;
    il2cpp_array* dtfiTokenHash;
} Il2CppDateTimeFormatInfo;
typedef struct Il2CppNumberFormatInfo
{
    il2cpp_object obj;
    il2cpp_array* numberGroupSizes;
    il2cpp_array* currencyGroupSizes;
    il2cpp_array* percentGroupSizes;
    il2cpp_string* positiveSign;
    il2cpp_string* negativeSign;
    il2cpp_string* numberDecimalSeparator;
    il2cpp_string* numberGroupSeparator;
    il2cpp_string* currencyGroupSeparator;
    il2cpp_string* currencyDecimalSeparator;
    il2cpp_string* currencySymbol;
    il2cpp_string* ansiCurrencySymbol;
    il2cpp_string* naNSymbol;
    il2cpp_string* positiveInfinitySymbol;
    il2cpp_string* negativeInfinitySymbol;
    il2cpp_string* percentDecimalSeparator;
    il2cpp_string* percentGroupSeparator;
    il2cpp_string* percentSymbol;
    il2cpp_string* perMilleSymbol;
    il2cpp_array* nativeDigits;
    int dataItem;
    int numberDecimalDigits;
    int currencyDecimalDigits;
    int currencyPositivePattern;
    int currencyNegativePattern;
    int numberNegativePattern;
    int percentPositivePattern;
    int percentNegativePattern;
    int percentDecimalDigits;
    int digitSubstitution;
    uint8_t readOnly;
    uint8_t useUserOverride;
    uint8_t isInvariant;
    uint8_t validForParseAsNumber;
    uint8_t validForParseAsCurrency;
} Il2CppNumberFormatInfo;
typedef struct Il2CppCultureData
{
    il2cpp_object obj;
    il2cpp_string* AMDesignator;
    il2cpp_string* PMDesignator;
    il2cpp_string* TimeSeparator;
    il2cpp_array* LongTimePatterns;
    il2cpp_array* ShortTimePatterns;
    uint32_t FirstDayOfWeek;
    uint32_t CalendarWeekRule;
} Il2CppCultureData;
typedef struct Il2CppCalendarData
{
    il2cpp_object obj;
    il2cpp_string* NativeName;
    il2cpp_array* ShortDatePatterns;
    il2cpp_array* YearMonthPatterns;
    il2cpp_array* LongDatePatterns;
    il2cpp_string* MonthDayPattern;
    il2cpp_array* EraNames;
    il2cpp_array* AbbreviatedEraNames;
    il2cpp_array* AbbreviatedEnglishEraNames;
    il2cpp_array* DayNames;
    il2cpp_array* AbbreviatedDayNames;
    il2cpp_array* SuperShortDayNames;
    il2cpp_array* MonthNames;
    il2cpp_array* AbbreviatedMonthNames;
    il2cpp_array* GenitiveMonthNames;
    il2cpp_array* GenitiveAbbreviatedMonthNames;
} Il2CppCalendarData;
typedef struct Il2CppCultureInfo
{
    il2cpp_object obj;
    uint8_t is_read_only;
    int32_t lcid;
    int32_t parent_lcid;
    int32_t datetime_index;
    int32_t number_index;
    int32_t default_calendar_type;
    uint8_t use_user_override;
    Il2CppNumberFormatInfo* number_format;
    Il2CppDateTimeFormatInfo* datetime_format;
    il2cpp_object* textinfo;
    il2cpp_string* name;
    il2cpp_string* englishname;
    il2cpp_string* nativename;
    il2cpp_string* iso3lang;
    il2cpp_string* iso2lang;
    il2cpp_string* win3lang;
    il2cpp_string* territory;
    il2cpp_array* native_calendar_names;
    il2cpp_string* compareinfo;
    const void* text_info_data;
    int dataItem;
    il2cpp_object* calendar;
    il2cpp_object* parent_culture;
    uint8_t constructed;
    il2cpp_array* cached_serialized_form;
    il2cpp_object* cultureData;
    uint8_t isInherited;
} Il2CppCultureInfo;
typedef struct Il2CppRegionInfo
{
    il2cpp_object obj;
    int32_t geo_id;
    il2cpp_string* iso2name;
    il2cpp_string* iso3name;
    il2cpp_string* win3name;
    il2cpp_string* english_name;
    il2cpp_string* native_name;
    il2cpp_string* currency_symbol;
    il2cpp_string* iso_currency_symbol;
    il2cpp_string* currency_english_name;
    il2cpp_string* currency_native_name;
} Il2CppRegionInfo;
typedef struct Il2CppSafeHandle
{
    il2cpp_object base;
    void* handle;
    int state;
    uint8_t owns_handle;
    uint8_t fullyInitialized;
} Il2CppSafeHandle;
typedef struct il2cpp_stringBuilder il2cpp_stringBuilder;
typedef struct il2cpp_stringBuilder
{
    il2cpp_object object;
    il2cpp_array* chunkChars;
    struct il2cpp_stringBuilder* chunkPrevious;
    int chunkLength;
    int chunkOffset;
    int maxCapacity;
} il2cpp_stringBuilder;
typedef struct Il2CppSocketAddress
{
    il2cpp_object base;
    int m_Size;
    il2cpp_array* data;
    uint8_t m_changed;
    int m_hash;
} Il2CppSocketAddress;
typedef struct Il2CppSortKey
{
    il2cpp_object base;
    il2cpp_string* str;
    il2cpp_array* key;
    int32_t options;
    int32_t lcid;
} Il2CppSortKey;
typedef struct Il2CppErrorWrapper
{
    il2cpp_object base;
    int32_t errorCode;
} Il2CppErrorWrapper;
typedef struct il2cpp_async_result
{
    il2cpp_object base;
    il2cpp_object* async_state;
    Il2CppWaitHandle* handle;
    il2cpp_delegate* async_delegate;
    void* data;
    Il2CppAsyncCall* object_data;
    uint8_t sync_completed;
    uint8_t completed;
    uint8_t endinvoke_called;
    il2cpp_object* async_callback;
    il2cpp_object* execution_context;
    il2cpp_object* original_context;
} il2cpp_async_result;
typedef struct Il2CppAsyncCall
{
    il2cpp_object base;
    Il2CppMethodMessage* msg;
    method_info* cb_method;
    il2cpp_delegate* cb_target;
    il2cpp_object* state;
    il2cpp_object* res;
    il2cpp_array* out_args;
} Il2CppAsyncCall;
typedef struct il2cpp_exceptionWrapper il2cpp_exceptionWrapper;
typedef struct il2cpp_exceptionWrapper
{
    il2cpp_exception* ex;
} il2cpp_exceptionWrapper;
typedef struct Il2CppIOAsyncResult
{
    il2cpp_object base;
    il2cpp_delegate* callback;
    il2cpp_object* state;
    Il2CppWaitHandle* wait_handle;
    uint8_t completed_synchronously;
    uint8_t completed;
} Il2CppIOAsyncResult;
typedef struct Il2CppSocketAsyncResult
{
    Il2CppIOAsyncResult base;
    il2cpp_object* socket;
    int32_t operation;
    il2cpp_exception* delayedException;
    il2cpp_object* endPoint;
    il2cpp_array* buffer;
    int32_t offset;
    int32_t size;
    int32_t socket_flags;
    il2cpp_object* acceptSocket;
    il2cpp_array* addresses;
    int32_t port;
    il2cpp_object* buffers;
    uint8_t reuseSocket;
    int32_t currentAddress;
    il2cpp_object* acceptedSocket;
    int32_t total;
    int32_t error;
    int32_t endCalled;
} Il2CppSocketAsyncResult;
typedef enum Il2CppResourceLocation
{
    IL2CPP_RESOURCE_LOCATION_EMBEDDED = 1,
    IL2CPP_RESOURCE_LOCATION_ANOTHER_ASSEMBLY = 2,
    IL2CPP_RESOURCE_LOCATION_IN_MANIFEST = 4
} Il2CppResourceLocation;
typedef struct Il2CppManifestResourceInfo
{
    il2cpp_object object;
    Il2CppReflectionAssembly* assembly;
    il2cpp_string* filename;
    uint32_t location;
} Il2CppManifestResourceInfo;
typedef struct Il2CppAppContext
{
    il2cpp_object obj;
    int32_t domain_id;
    int32_t context_id;
    void* static_data;
} Il2CppAppContext;
typedef struct Il2CppDecimal
{
    uint16_t reserved;
    union
    {
        struct
        {
            uint8_t scale;
            uint8_t sign;
        } u;
        uint16_t signscale;
    } u;
    uint32_t Hi32;
    union
    {
        struct
        {
            uint32_t Lo32;
            uint32_t Mid32;
        } v;
        uint64_t Lo64;
    } v;
} Il2CppDecimal;
typedef struct Il2CppDouble
{
    uint32_t mantLo : 32;
    uint32_t mantHi : 20;
    uint32_t exp : 11;
    uint32_t sign : 1;
} Il2CppDouble;
typedef union Il2CppDouble_double
{
    Il2CppDouble s;
    double d;
} Il2CppDouble_double;
typedef enum Il2CppDecimalCompareResult
{
    IL2CPP_DECIMAL_CMP_LT = -1,
    IL2CPP_DECIMAL_CMP_EQ,
    IL2CPP_DECIMAL_CMP_GT
} Il2CppDecimalCompareResult;
typedef struct Il2CppSingle
{
    uint32_t mant : 23;
    uint32_t exp : 8;
    uint32_t sign : 1;
} Il2CppSingle;
typedef union Il2CppSingle_float
{
    Il2CppSingle s;
    float f;
} Il2CppSingle_float;
