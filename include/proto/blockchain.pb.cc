// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: blockchain.proto

#include "blockchain.pb.h"

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
namespace BlockchainProto {
constexpr Transaction::Transaction(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : sender_id_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , receiver_id_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , amount_(0){}
struct TransactionDefaultTypeInternal {
  constexpr TransactionDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~TransactionDefaultTypeInternal() {}
  union {
    Transaction _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT TransactionDefaultTypeInternal _Transaction_default_instance_;
constexpr Block::Block(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : t_actions_lst_()
  , id_block_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , id_prev_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , nonce_(0){}
struct BlockDefaultTypeInternal {
  constexpr BlockDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~BlockDefaultTypeInternal() {}
  union {
    Block _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT BlockDefaultTypeInternal _Block_default_instance_;
constexpr Blockchain::Blockchain(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : chain_(){}
struct BlockchainDefaultTypeInternal {
  constexpr BlockchainDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~BlockchainDefaultTypeInternal() {}
  union {
    Blockchain _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT BlockchainDefaultTypeInternal _Blockchain_default_instance_;
}  // namespace BlockchainProto
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_blockchain_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_blockchain_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_blockchain_2eproto = nullptr;

const uint32_t TableStruct_blockchain_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::BlockchainProto::Transaction, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::BlockchainProto::Transaction, sender_id_),
  PROTOBUF_FIELD_OFFSET(::BlockchainProto::Transaction, receiver_id_),
  PROTOBUF_FIELD_OFFSET(::BlockchainProto::Transaction, amount_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::BlockchainProto::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::BlockchainProto::Block, id_block_),
  PROTOBUF_FIELD_OFFSET(::BlockchainProto::Block, id_prev_),
  PROTOBUF_FIELD_OFFSET(::BlockchainProto::Block, nonce_),
  PROTOBUF_FIELD_OFFSET(::BlockchainProto::Block, t_actions_lst_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::BlockchainProto::Blockchain, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::BlockchainProto::Blockchain, chain_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::BlockchainProto::Transaction)},
  { 9, -1, -1, sizeof(::BlockchainProto::Block)},
  { 19, -1, -1, sizeof(::BlockchainProto::Blockchain)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::BlockchainProto::_Transaction_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::BlockchainProto::_Block_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::BlockchainProto::_Blockchain_default_instance_),
};

const char descriptor_table_protodef_blockchain_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020blockchain.proto\022\017BlockchainProto\"E\n\013T"
  "ransaction\022\021\n\tsender_id\030\001 \001(\t\022\023\n\013receive"
  "r_id\030\002 \001(\t\022\016\n\006amount\030\003 \001(\001\"n\n\005Block\022\020\n\010i"
  "d_block\030\001 \001(\t\022\017\n\007id_prev\030\002 \001(\t\022\r\n\005nonce\030"
  "\003 \001(\005\0223\n\rt_actions_lst\030\004 \003(\0132\034.Blockchai"
  "nProto.Transaction\"3\n\nBlockchain\022%\n\005chai"
  "n\030\001 \003(\0132\026.BlockchainProto.Blockb\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_blockchain_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_blockchain_2eproto = {
  false, false, 279, descriptor_table_protodef_blockchain_2eproto, "blockchain.proto", 
  &descriptor_table_blockchain_2eproto_once, nullptr, 0, 3,
  schemas, file_default_instances, TableStruct_blockchain_2eproto::offsets,
  file_level_metadata_blockchain_2eproto, file_level_enum_descriptors_blockchain_2eproto, file_level_service_descriptors_blockchain_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_blockchain_2eproto_getter() {
  return &descriptor_table_blockchain_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_blockchain_2eproto(&descriptor_table_blockchain_2eproto);
namespace BlockchainProto {

// ===================================================================

class Transaction::_Internal {
 public:
};

Transaction::Transaction(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:BlockchainProto.Transaction)
}
Transaction::Transaction(const Transaction& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  sender_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    sender_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_sender_id().empty()) {
    sender_id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_sender_id(), 
      GetArenaForAllocation());
  }
  receiver_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    receiver_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_receiver_id().empty()) {
    receiver_id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_receiver_id(), 
      GetArenaForAllocation());
  }
  amount_ = from.amount_;
  // @@protoc_insertion_point(copy_constructor:BlockchainProto.Transaction)
}

inline void Transaction::SharedCtor() {
sender_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  sender_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
receiver_id_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  receiver_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
amount_ = 0;
}

Transaction::~Transaction() {
  // @@protoc_insertion_point(destructor:BlockchainProto.Transaction)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Transaction::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  sender_id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  receiver_id_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Transaction::ArenaDtor(void* object) {
  Transaction* _this = reinterpret_cast< Transaction* >(object);
  (void)_this;
}
void Transaction::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Transaction::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Transaction::Clear() {
// @@protoc_insertion_point(message_clear_start:BlockchainProto.Transaction)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  sender_id_.ClearToEmpty();
  receiver_id_.ClearToEmpty();
  amount_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Transaction::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string sender_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_sender_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "BlockchainProto.Transaction.sender_id"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string receiver_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_receiver_id();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "BlockchainProto.Transaction.receiver_id"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // double amount = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 25)) {
          amount_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr);
          ptr += sizeof(double);
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

uint8_t* Transaction::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:BlockchainProto.Transaction)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string sender_id = 1;
  if (!this->_internal_sender_id().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_sender_id().data(), static_cast<int>(this->_internal_sender_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "BlockchainProto.Transaction.sender_id");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_sender_id(), target);
  }

  // string receiver_id = 2;
  if (!this->_internal_receiver_id().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_receiver_id().data(), static_cast<int>(this->_internal_receiver_id().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "BlockchainProto.Transaction.receiver_id");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_receiver_id(), target);
  }

  // double amount = 3;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_amount = this->_internal_amount();
  uint64_t raw_amount;
  memcpy(&raw_amount, &tmp_amount, sizeof(tmp_amount));
  if (raw_amount != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteDoubleToArray(3, this->_internal_amount(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:BlockchainProto.Transaction)
  return target;
}

size_t Transaction::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:BlockchainProto.Transaction)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string sender_id = 1;
  if (!this->_internal_sender_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_sender_id());
  }

  // string receiver_id = 2;
  if (!this->_internal_receiver_id().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_receiver_id());
  }

  // double amount = 3;
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_amount = this->_internal_amount();
  uint64_t raw_amount;
  memcpy(&raw_amount, &tmp_amount, sizeof(tmp_amount));
  if (raw_amount != 0) {
    total_size += 1 + 8;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Transaction::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Transaction::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Transaction::GetClassData() const { return &_class_data_; }

void Transaction::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Transaction *>(to)->MergeFrom(
      static_cast<const Transaction &>(from));
}


void Transaction::MergeFrom(const Transaction& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:BlockchainProto.Transaction)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_sender_id().empty()) {
    _internal_set_sender_id(from._internal_sender_id());
  }
  if (!from._internal_receiver_id().empty()) {
    _internal_set_receiver_id(from._internal_receiver_id());
  }
  static_assert(sizeof(uint64_t) == sizeof(double), "Code assumes uint64_t and double are the same size.");
  double tmp_amount = from._internal_amount();
  uint64_t raw_amount;
  memcpy(&raw_amount, &tmp_amount, sizeof(tmp_amount));
  if (raw_amount != 0) {
    _internal_set_amount(from._internal_amount());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Transaction::CopyFrom(const Transaction& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:BlockchainProto.Transaction)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Transaction::IsInitialized() const {
  return true;
}

void Transaction::InternalSwap(Transaction* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &sender_id_, lhs_arena,
      &other->sender_id_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &receiver_id_, lhs_arena,
      &other->receiver_id_, rhs_arena
  );
  swap(amount_, other->amount_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Transaction::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_blockchain_2eproto_getter, &descriptor_table_blockchain_2eproto_once,
      file_level_metadata_blockchain_2eproto[0]);
}

// ===================================================================

class Block::_Internal {
 public:
};

Block::Block(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  t_actions_lst_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:BlockchainProto.Block)
}
Block::Block(const Block& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      t_actions_lst_(from.t_actions_lst_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  id_block_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    id_block_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_id_block().empty()) {
    id_block_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_id_block(), 
      GetArenaForAllocation());
  }
  id_prev_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    id_prev_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_id_prev().empty()) {
    id_prev_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_id_prev(), 
      GetArenaForAllocation());
  }
  nonce_ = from.nonce_;
  // @@protoc_insertion_point(copy_constructor:BlockchainProto.Block)
}

inline void Block::SharedCtor() {
id_block_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  id_block_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
id_prev_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  id_prev_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
nonce_ = 0;
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:BlockchainProto.Block)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Block::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  id_block_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  id_prev_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Block::ArenaDtor(void* object) {
  Block* _this = reinterpret_cast< Block* >(object);
  (void)_this;
}
void Block::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:BlockchainProto.Block)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  t_actions_lst_.Clear();
  id_block_.ClearToEmpty();
  id_prev_.ClearToEmpty();
  nonce_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Block::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string id_block = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_id_block();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "BlockchainProto.Block.id_block"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string id_prev = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_id_prev();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "BlockchainProto.Block.id_prev"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 nonce = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          nonce_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .BlockchainProto.Transaction t_actions_lst = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_t_actions_lst(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<34>(ptr));
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

uint8_t* Block::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:BlockchainProto.Block)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string id_block = 1;
  if (!this->_internal_id_block().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_id_block().data(), static_cast<int>(this->_internal_id_block().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "BlockchainProto.Block.id_block");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_id_block(), target);
  }

  // string id_prev = 2;
  if (!this->_internal_id_prev().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_id_prev().data(), static_cast<int>(this->_internal_id_prev().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "BlockchainProto.Block.id_prev");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_id_prev(), target);
  }

  // int32 nonce = 3;
  if (this->_internal_nonce() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->_internal_nonce(), target);
  }

  // repeated .BlockchainProto.Transaction t_actions_lst = 4;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_t_actions_lst_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(4, this->_internal_t_actions_lst(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:BlockchainProto.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:BlockchainProto.Block)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .BlockchainProto.Transaction t_actions_lst = 4;
  total_size += 1UL * this->_internal_t_actions_lst_size();
  for (const auto& msg : this->t_actions_lst_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // string id_block = 1;
  if (!this->_internal_id_block().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_id_block());
  }

  // string id_prev = 2;
  if (!this->_internal_id_prev().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_id_prev());
  }

  // int32 nonce = 3;
  if (this->_internal_nonce() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_nonce());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Block::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Block::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Block::GetClassData() const { return &_class_data_; }

void Block::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Block *>(to)->MergeFrom(
      static_cast<const Block &>(from));
}


void Block::MergeFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:BlockchainProto.Block)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  t_actions_lst_.MergeFrom(from.t_actions_lst_);
  if (!from._internal_id_block().empty()) {
    _internal_set_id_block(from._internal_id_block());
  }
  if (!from._internal_id_prev().empty()) {
    _internal_set_id_prev(from._internal_id_prev());
  }
  if (from._internal_nonce() != 0) {
    _internal_set_nonce(from._internal_nonce());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:BlockchainProto.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Block::IsInitialized() const {
  return true;
}

void Block::InternalSwap(Block* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  t_actions_lst_.InternalSwap(&other->t_actions_lst_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &id_block_, lhs_arena,
      &other->id_block_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &id_prev_, lhs_arena,
      &other->id_prev_, rhs_arena
  );
  swap(nonce_, other->nonce_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Block::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_blockchain_2eproto_getter, &descriptor_table_blockchain_2eproto_once,
      file_level_metadata_blockchain_2eproto[1]);
}

// ===================================================================

class Blockchain::_Internal {
 public:
};

Blockchain::Blockchain(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  chain_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:BlockchainProto.Blockchain)
}
Blockchain::Blockchain(const Blockchain& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      chain_(from.chain_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:BlockchainProto.Blockchain)
}

inline void Blockchain::SharedCtor() {
}

Blockchain::~Blockchain() {
  // @@protoc_insertion_point(destructor:BlockchainProto.Blockchain)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Blockchain::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Blockchain::ArenaDtor(void* object) {
  Blockchain* _this = reinterpret_cast< Blockchain* >(object);
  (void)_this;
}
void Blockchain::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Blockchain::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Blockchain::Clear() {
// @@protoc_insertion_point(message_clear_start:BlockchainProto.Blockchain)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  chain_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Blockchain::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .BlockchainProto.Block chain = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_chain(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
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

uint8_t* Blockchain::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:BlockchainProto.Blockchain)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .BlockchainProto.Block chain = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_chain_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_chain(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:BlockchainProto.Blockchain)
  return target;
}

size_t Blockchain::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:BlockchainProto.Blockchain)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .BlockchainProto.Block chain = 1;
  total_size += 1UL * this->_internal_chain_size();
  for (const auto& msg : this->chain_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Blockchain::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Blockchain::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Blockchain::GetClassData() const { return &_class_data_; }

void Blockchain::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Blockchain *>(to)->MergeFrom(
      static_cast<const Blockchain &>(from));
}


void Blockchain::MergeFrom(const Blockchain& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:BlockchainProto.Blockchain)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  chain_.MergeFrom(from.chain_);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Blockchain::CopyFrom(const Blockchain& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:BlockchainProto.Blockchain)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Blockchain::IsInitialized() const {
  return true;
}

void Blockchain::InternalSwap(Blockchain* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  chain_.InternalSwap(&other->chain_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Blockchain::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_blockchain_2eproto_getter, &descriptor_table_blockchain_2eproto_once,
      file_level_metadata_blockchain_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace BlockchainProto
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::BlockchainProto::Transaction* Arena::CreateMaybeMessage< ::BlockchainProto::Transaction >(Arena* arena) {
  return Arena::CreateMessageInternal< ::BlockchainProto::Transaction >(arena);
}
template<> PROTOBUF_NOINLINE ::BlockchainProto::Block* Arena::CreateMaybeMessage< ::BlockchainProto::Block >(Arena* arena) {
  return Arena::CreateMessageInternal< ::BlockchainProto::Block >(arena);
}
template<> PROTOBUF_NOINLINE ::BlockchainProto::Blockchain* Arena::CreateMaybeMessage< ::BlockchainProto::Blockchain >(Arena* arena) {
  return Arena::CreateMessageInternal< ::BlockchainProto::Blockchain >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
