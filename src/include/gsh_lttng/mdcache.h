
#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER mdcache

#if !defined(GANESHA_LTTNG_MDCACHE_TP_H) || \
	defined(TRACEPOINT_HEADER_MULTI_READ)
#define GANESHA_LTTNG_MDCACHE_TP_H

#include <lttng/tracepoint.h>

/**
 * @brief Trace an increase in refcount of an entry
 *
 * @param[in] function	Name of function taking ref
 * @param[in] line	Line number of call
 * @param[in] entry	Address of entry
 * @param[in] refcnt	Refcount after increase
 */
TRACEPOINT_EVENT(
	mdcache,
	mdc_lru_ref,
	TP_ARGS(const char *, function,
		int, line,
		void *, entry,
		int32_t, refcnt),
	TP_FIELDS(
		ctf_string(function, function)
		ctf_integer(int, line, line)
		ctf_integer_hex(void *, entry, entry)
		ctf_integer(int32_t, refcnt, refcnt)
	)
)

TRACEPOINT_LOGLEVEL(
	mdcache,
	mdc_lru_ref,
	TRACE_INFO)

/**
 * @brief Trace a decrease in refcount of an entry
 *
 * @param[in] function	Name of function releasing ref
 * @param[in] line	Line number of call
 * @param[in] entry	Address of entry
 * @param[in] refcnt	Refcount after decrease
 */
TRACEPOINT_EVENT(
	mdcache,
	mdc_lru_unref,
	TP_ARGS(const char *, function,
		int, line,
		void *, entry,
		int32_t, refcnt),
	TP_FIELDS(
		ctf_string(function, function)
		ctf_integer(int, line, line)
		ctf_integer_hex(void *, entry, entry)
		ctf_integer(int32_t, refcnt, refcnt)
	)
)

TRACEPOINT_LOGLEVEL(
	mdcache,
	mdc_lru_unref,
	TRACE_INFO)

/**
 * @brief Trace a QLOCK event
 *
 * @param[in] function	Name of function taking ref
 * @param[in] line	Line number of call
 */
TRACEPOINT_EVENT(
	mdcache,
	qlock,
	TP_ARGS(const char *, function,
		int, line,
		void *, qlane),
	TP_FIELDS(
		ctf_string(function, function)
		ctf_integer(int, line, line)
		ctf_integer_hex(void *, qlane, qlane)
	)
)

TRACEPOINT_LOGLEVEL(
	mdcache,
	qlock,
	TRACE_INFO)

/**
 * @brief Trace a QUNLOCK event
 *
 * @param[in] function	Name of function taking ref
 * @param[in] line	Line number of call
 */
TRACEPOINT_EVENT(
	mdcache,
	qunlock,
	TP_ARGS(const char *, function,
		int, line,
		void *, qlane),
	TP_FIELDS(
		ctf_string(function, function)
		ctf_integer(int, line, line)
		ctf_integer_hex(void *, qlane, qlane)
	)
)

TRACEPOINT_LOGLEVEL(
	mdcache,
	qunlock,
	TRACE_INFO)

/**
 * @brief Trace a reap (reuse) of an entry
 *
 * @param[in] entry	Address of entry
 */
TRACEPOINT_EVENT(
	mdcache,
	mdc_lru_reap,
	TP_ARGS(const char *, function,
		int, line,
		void *, entry,
		int32_t, refcnt),
	TP_FIELDS(
		ctf_string(function, function)
		ctf_integer(int, line, line)
		ctf_integer_hex(void *, entry, entry)
		ctf_integer(int32_t, refcnt, refcnt)
	)
)

TRACEPOINT_LOGLEVEL(
	mdcache,
	mdc_lru_reap,
	TRACE_INFO)

/**
 * @brief Trace a alloc of a new entry
 *
 * @param[in] entry	Address of entry
 */
TRACEPOINT_EVENT(
	mdcache,
	mdc_lru_get,
	TP_ARGS(const char *, function,
		int, line,
		void *, entry,
		int32_t, refcnt),
	TP_FIELDS(
		ctf_string(function, function)
		ctf_integer(int, line, line)
		ctf_integer_hex(void *, entry, entry)
		ctf_integer(int32_t, refcnt, refcnt)
	)
)

TRACEPOINT_LOGLEVEL(
	mdcache,
	mdc_lru_get,
	TRACE_INFO)

/**
 * @brief Trace insertion of an entry in the LRU
 *
 * @param[in] entry	Address of entry
 */
TRACEPOINT_EVENT(
	mdcache,
	mdc_lru_insert,
	TP_ARGS(const char *, function,
		int, line,
		void *, entry,
		int32_t, refcnt),
	TP_FIELDS(
		ctf_string(function, function)
		ctf_integer(int, line, line)
		ctf_integer_hex(void *, entry, entry)
		ctf_integer(int32_t, refcnt, refcnt)
	)
)

TRACEPOINT_LOGLEVEL(
	mdcache,
	mdc_lru_insert,
	TRACE_INFO)

/**
 * @brief Trace removal of an entry from the LRU
 *
 * @param[in] entry	Address of entry
 */
TRACEPOINT_EVENT(
	mdcache,
	mdc_lru_remove,
	TP_ARGS(const char *, function,
		int, line,
		void *, entry,
		int32_t, refcnt),
	TP_FIELDS(
		ctf_string(function, function)
		ctf_integer(int, line, line)
		ctf_integer_hex(void *, entry, entry)
		ctf_integer(int32_t, refcnt, refcnt)
	)
)

TRACEPOINT_LOGLEVEL(
	mdcache,
	mdc_lru_remove,
	TRACE_INFO)

/**
 * @brief Trace killing of entry
 *
 * @param[in] entry	Address of entry
 */
TRACEPOINT_EVENT(
	mdcache,
	mdc_kill_entry,
	TP_ARGS(const char *, function,
		int, line,
		void *, entry,
		int32_t, refcnt,
		int32_t, freed),
	TP_FIELDS(
		ctf_string(function, function)
		ctf_integer(int, line, line)
		ctf_integer_hex(void *, entry, entry)
		ctf_integer(int32_t, refcnt, refcnt)
		ctf_integer(int32_t, freed, freed)
	)
)

TRACEPOINT_LOGLEVEL(
	mdcache,
	mdc_kill_entry,
	TRACE_INFO)

/**
 * @brief Trace readdir cache populate
 *
 * @param[in] entry	Address of entry
 */
TRACEPOINT_EVENT(
	mdcache,
	mdc_readdir_populate,
	TP_ARGS(const char *, function,
		int, line,
		void *, entry,
		int32_t, refcnt),
	TP_FIELDS(
		ctf_string(function, function)
		ctf_integer(int, line, line)
		ctf_integer_hex(void *, entry, entry)
		ctf_integer(int32_t, refcnt, refcnt)
	)
)

TRACEPOINT_LOGLEVEL(
	mdcache,
	mdc_readdir_populate,
	TRACE_INFO)

/**
 * @brief Trace readdir
 *
 * @param[in] entry	Address of entry
 */
TRACEPOINT_EVENT(
	mdcache,
	mdc_readdir,
	TP_ARGS(const char *, function,
		int, line,
		void *, entry,
		int32_t, refcnt),
	TP_FIELDS(
		ctf_string(function, function)
		ctf_integer(int, line, line)
		ctf_integer_hex(void *, entry, entry)
		ctf_integer(int32_t, refcnt, refcnt)
	)
)

TRACEPOINT_LOGLEVEL(
	mdcache,
	mdc_readdir,
	TRACE_INFO)

#endif /* GANESHA_LTTNG_MDCACHE_TP_H */

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "gsh_lttng/mdcache.h"

#include <lttng/tracepoint-event.h>
