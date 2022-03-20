// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Login.proto

#include "Login.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace Protocol {
constexpr C_LOGIN::C_LOGIN(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : name_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct C_LOGINDefaultTypeInternal {
  constexpr C_LOGINDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~C_LOGINDefaultTypeInternal() {}
  union {
    C_LOGIN _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT C_LOGINDefaultTypeInternal _C_LOGIN_default_instance_;
constexpr S_LOGIN_RESULT::S_LOGIN_RESULT(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : players_(nullptr)
  , success_(false){}
struct S_LOGIN_RESULTDefaultTypeInternal {
  constexpr S_LOGIN_RESULTDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~S_LOGIN_RESULTDefaultTypeInternal() {}
  union {
    S_LOGIN_RESULT _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT S_LOGIN_RESULTDefaultTypeInternal _S_LOGIN_RESULT_default_instance_;
}  // namespace Protocol
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_Login_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_Login_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_Login_2eproto = nullptr;

const uint32_t TableStruct_Login_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::C_LOGIN, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::C_LOGIN, name_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::S_LOGIN_RESULT, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::S_LOGIN_RESULT, success_),
  PROTOBUF_FIELD_OFFSET(::Protocol::S_LOGIN_RESULT, players_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Protocol::C_LOGIN)},
  { 7, -1, -1, sizeof(::Protocol::S_LOGIN_RESULT)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Protocol::_C_LOGIN_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Protocol::_S_LOGIN_RESULT_default_instance_),
};

const char descriptor_table_protodef_Login_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\013Login.proto\022\010Protocol\032\014Player.proto\"\027\n"
  "\007C_LOGIN\022\014\n\004name\030\001 \001(\t\"D\n\016S_LOGIN_RESULT"
  "\022\017\n\007success\030\001 \001(\010\022!\n\007players\030\002 \001(\0132\020.Pro"
  "tocol.Playerb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_Login_2eproto_deps[1] = {
  &::descriptor_table_Player_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_Login_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Login_2eproto = {
  false, false, 140, descriptor_table_protodef_Login_2eproto, "Login.proto", 
  &descriptor_table_Login_2eproto_once, descriptor_table_Login_2eproto_deps, 1, 2,
  schemas, file_default_instances, TableStruct_Login_2eproto::offsets,
  file_level_metadata_Login_2eproto, file_level_enum_descriptors_Login_2eproto, file_level_service_descriptors_Login_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_Login_2eproto_getter() {
  return &descriptor_table_Login_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_Login_2eproto(&descriptor_table_Login_2eproto);
namespace Protocol {

// ===================================================================

class C_LOGIN::_Internal {
 public:
};

C_LOGIN::C_LOGIN(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Protocol.C_LOGIN)
}
C_LOGIN::C_LOGIN(const C_LOGIN& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_name().empty()) {
    name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_name(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:Protocol.C_LOGIN)
}

inline void C_LOGIN::SharedCtor() {
name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

C_LOGIN::~C_LOGIN() {
  // @@protoc_insertion_point(destructor:Protocol.C_LOGIN)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void C_LOGIN::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void C_LOGIN::ArenaDtor(void* object) {
  C_LOGIN* _this = reinterpret_cast< C_LOGIN* >(object);
  (void)_this;
}
void C_LOGIN::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void C_LOGIN::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void C_LOGIN::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.C_LOGIN)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* C_LOGIN::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Protocol.C_LOGIN.name"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* C_LOGIN::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.C_LOGIN)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Protocol.C_LOGIN.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.C_LOGIN)
  return target;
}

size_t C_LOGIN::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.C_LOGIN)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData C_LOGIN::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    C_LOGIN::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*C_LOGIN::GetClassData() const { return &_class_data_; }

void C_LOGIN::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<C_LOGIN *>(to)->MergeFrom(
      static_cast<const C_LOGIN &>(from));
}


void C_LOGIN::MergeFrom(const C_LOGIN& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.C_LOGIN)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_name().empty()) {
    _internal_set_name(from._internal_name());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void C_LOGIN::CopyFrom(const C_LOGIN& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.C_LOGIN)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool C_LOGIN::IsInitialized() const {
  return true;
}

void C_LOGIN::InternalSwap(C_LOGIN* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &name_, lhs_arena,
      &other->name_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata C_LOGIN::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Login_2eproto_getter, &descriptor_table_Login_2eproto_once,
      file_level_metadata_Login_2eproto[0]);
}

// ===================================================================

class S_LOGIN_RESULT::_Internal {
 public:
  static const ::Protocol::Player& players(const S_LOGIN_RESULT* msg);
};

const ::Protocol::Player&
S_LOGIN_RESULT::_Internal::players(const S_LOGIN_RESULT* msg) {
  return *msg->players_;
}
void S_LOGIN_RESULT::clear_players() {
  if (GetArenaForAllocation() == nullptr && players_ != nullptr) {
    delete players_;
  }
  players_ = nullptr;
}
S_LOGIN_RESULT::S_LOGIN_RESULT(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Protocol.S_LOGIN_RESULT)
}
S_LOGIN_RESULT::S_LOGIN_RESULT(const S_LOGIN_RESULT& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_players()) {
    players_ = new ::Protocol::Player(*from.players_);
  } else {
    players_ = nullptr;
  }
  success_ = from.success_;
  // @@protoc_insertion_point(copy_constructor:Protocol.S_LOGIN_RESULT)
}

inline void S_LOGIN_RESULT::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&players_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&success_) -
    reinterpret_cast<char*>(&players_)) + sizeof(success_));
}

S_LOGIN_RESULT::~S_LOGIN_RESULT() {
  // @@protoc_insertion_point(destructor:Protocol.S_LOGIN_RESULT)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void S_LOGIN_RESULT::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete players_;
}

void S_LOGIN_RESULT::ArenaDtor(void* object) {
  S_LOGIN_RESULT* _this = reinterpret_cast< S_LOGIN_RESULT* >(object);
  (void)_this;
}
void S_LOGIN_RESULT::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void S_LOGIN_RESULT::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void S_LOGIN_RESULT::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.S_LOGIN_RESULT)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && players_ != nullptr) {
    delete players_;
  }
  players_ = nullptr;
  success_ = false;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* S_LOGIN_RESULT::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bool success = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          success_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .Protocol.Player players = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_players(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* S_LOGIN_RESULT::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.S_LOGIN_RESULT)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // bool success = 1;
  if (this->_internal_success() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(1, this->_internal_success(), target);
  }

  // .Protocol.Player players = 2;
  if (this->_internal_has_players()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        2, _Internal::players(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.S_LOGIN_RESULT)
  return target;
}

size_t S_LOGIN_RESULT::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.S_LOGIN_RESULT)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .Protocol.Player players = 2;
  if (this->_internal_has_players()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *players_);
  }

  // bool success = 1;
  if (this->_internal_success() != 0) {
    total_size += 1 + 1;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData S_LOGIN_RESULT::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    S_LOGIN_RESULT::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*S_LOGIN_RESULT::GetClassData() const { return &_class_data_; }

void S_LOGIN_RESULT::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<S_LOGIN_RESULT *>(to)->MergeFrom(
      static_cast<const S_LOGIN_RESULT &>(from));
}


void S_LOGIN_RESULT::MergeFrom(const S_LOGIN_RESULT& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.S_LOGIN_RESULT)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_players()) {
    _internal_mutable_players()->::Protocol::Player::MergeFrom(from._internal_players());
  }
  if (from._internal_success() != 0) {
    _internal_set_success(from._internal_success());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void S_LOGIN_RESULT::CopyFrom(const S_LOGIN_RESULT& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.S_LOGIN_RESULT)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool S_LOGIN_RESULT::IsInitialized() const {
  return true;
}

void S_LOGIN_RESULT::InternalSwap(S_LOGIN_RESULT* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(S_LOGIN_RESULT, success_)
      + sizeof(S_LOGIN_RESULT::success_)
      - PROTOBUF_FIELD_OFFSET(S_LOGIN_RESULT, players_)>(
          reinterpret_cast<char*>(&players_),
          reinterpret_cast<char*>(&other->players_));
}

::PROTOBUF_NAMESPACE_ID::Metadata S_LOGIN_RESULT::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_Login_2eproto_getter, &descriptor_table_Login_2eproto_once,
      file_level_metadata_Login_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Protocol::C_LOGIN* Arena::CreateMaybeMessage< ::Protocol::C_LOGIN >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::C_LOGIN >(arena);
}
template<> PROTOBUF_NOINLINE ::Protocol::S_LOGIN_RESULT* Arena::CreateMaybeMessage< ::Protocol::S_LOGIN_RESULT >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::S_LOGIN_RESULT >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
