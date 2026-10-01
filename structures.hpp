#pragma once
// Partial x86 layouts; generated 2026-10-01 09:49:47.
// These are memory views, not complete C++ game classes.

#include <cstddef>
#include <cstdint>

namespace nulvex::structures {
struct CEntInfo32 { uint32_t entity; int32_t serial; int32_t prev; int32_t next; };
static_assert(sizeof(CEntInfo32) == 16); // live entity-list stride

struct ClientClass32 {
    uint32_t create_fn, create_event_fn, network_name, recv_table, next;
    int32_t class_id;
};
static_assert(sizeof(ClientClass32) == 24); // traversed live class chain

struct RecvTable32 { uint32_t props; int32_t prop_count; uint32_t decoder, name; };
static_assert(sizeof(RecvTable32) == 16); // traversed live RecvTables

struct RecvProp32 {
    uint32_t name;
    int32_t type, flags, string_buffer_size, inside_array;
    uint32_t extra_data, array_prop, array_length_proxy, proxy_fn, data_table_proxy_fn;
    uint32_t data_table;
    int32_t offset, element_stride, elements;
    uint32_t parent_array_prop_name;
};
static_assert(sizeof(RecvProp32) == 60); // traversed live RecvProps

// Field locations are validated on sampled live players for this client build.
#pragma pack(push, 1)
struct CTerrorPlayerPartial {
    uint8_t unknown_0000[0xE4];
    int32_t m_iTeamNum; // 0xE4, 4/4 live samples
    uint8_t unknown_00E8[0x4];
    int32_t m_iHealth; // 0xEC, 4/4 live samples
    uint8_t unknown_00F0[0x34];
    float m_vecOrigin[3]; // 0x124, 4/4 live samples
    uint8_t unknown_0130[0x17];
    uint8_t m_lifeState; // 0x147, 4/4 live samples
    uint8_t unknown_0148[0x1B44];
    int32_t m_survivorCharacter; // 0x1C8C, 4/4 live samples
    int32_t m_zombieClass; // 0x1C90, 2/2 live samples
    uint8_t unknown_1C94[0x348];
    int32_t m_iMaxHealth; // 0x1FDC, 4/4 live samples
};
#pragma pack(pop)
static_assert(offsetof(CTerrorPlayerPartial, m_iTeamNum) == 0xE4);
static_assert(offsetof(CTerrorPlayerPartial, m_iHealth) == 0xEC);
static_assert(offsetof(CTerrorPlayerPartial, m_vecOrigin) == 0x124);
static_assert(offsetof(CTerrorPlayerPartial, m_lifeState) == 0x147);
static_assert(offsetof(CTerrorPlayerPartial, m_survivorCharacter) == 0x1C8C);
static_assert(offsetof(CTerrorPlayerPartial, m_zombieClass) == 0x1C90);
static_assert(offsetof(CTerrorPlayerPartial, m_iMaxHealth) == 0x1FDC);
} // namespace nulvex::structures
