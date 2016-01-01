/* Copyright (c) 2013-2015 The Squash Authors
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Authors:
 *   Evan Nemerson <evan@nemerson.com>
 */

#include <assert.h>
#include <squash/internal.h>

/**
 * @defgroup SquashStatus SquashStatus
 * @brief Response status codes.
 *
 * @{
 */

/**
 * @enum SquashStatus
 * @brief Status codes
 */

/**
 * @var SquashStatus::SQUASH_OK
 * @brief Operation completed successfully.
 */

/**
 * @var SquashStatus::SQUASH_PROCESSING
 * @brief Operation partially completed.
 */

/**
 * @var SquashStatus::SQUASH_END_OF_STREAM
 * @brief Reached the end of the stream while decoding.
 */

/**
 * @var SquashStatus::SQUASH_FAILED
 * @brief Operation failed.
 */

/**
 * @var SquashStatus::SQUASH_UNABLE_TO_LOAD
 * @brief Unable to load the requested resource.
 */

/**
 * @var SquashStatus::SQUASH_BAD_PARAM
 * @brief One or more of the parameters were not valid.
 */

/**
 * @var SquashStatus::SQUASH_BAD_VALUE
 * @brief One or more parameter values was not valid.
 */

/**
 * @var SquashStatus::SQUASH_MEMORY
 * @brief Not enough memory is available.
 */

/**
 * @var SquashStatus::SQUASH_BUFFER_FULL
 * @brief Insufficient space in buffer.
 */

/**
 * @var SquashStatus::SQUASH_BUFFER_EMPTY
 * @brief Supplied buffer was empty.
 */

/**
 * @var SquashStatus::SQUASH_STATE
 * @brief Performing the requested operation from the current state is
 *   not supported.
 */

/**
 * @var SquashStatus::SQUASH_INVALID_OPERATION
 * @brief The requested operation is not available.
 */

/**
 * @var SquashStatus::SQUASH_NOT_FOUND
 * @brief The requested codec could not be found.
 */

/**
 * @var SquashStatus::SQUASH_INVALID_BUFFER
 * @brief A buffer passed to squash was invalid
 */

/**
 * @var SquashStatus::SQUASH_IO
 * @brief An input/output error occurred
 *
 * There is a good chance errno will have additional details, though
 * it is not guaranteed.
 */

/**
 * @var SquashStatus::SQUASH_RANGE
 * @brief A buffer was too large to be usable
 *
 * While Squash uses `size_t` for buffer sizes, not all libraries used
 * by plugins do.  Many use `int`, `long`, `unsigned int`, etc., which
 * may be smaller than size_t (or, less likely, larger).
 *
 * In the event that converting a value between representations is not
 * possible @ref SQUASH_RANGE will be returned.
 */

/**
 * @brief Get a string representation of a status code.
 *
 * @param status The status.
 * @return A string describing @a status
 */
const char*
squash_status_to_string (SquashStatus status) {
  switch (status) {
    case SQUASH_OK:
      return "Operation completed successfully";
    case SQUASH_PROCESSING:
      return "Operation partially completed";
    case SQUASH_END_OF_STREAM:
      return "End of stream reached";
    case SQUASH_FAILED:
      return "Operation failed";
    case SQUASH_UNABLE_TO_LOAD:
      return "Unable to load the requested resource";
    case SQUASH_BAD_PARAM:
      return "One or more of the parameters were not valid";
    case SQUASH_BAD_VALUE:
      return "One or more parameter values was not valid";
    case SQUASH_MEMORY:
      return "Not enough memory is available";
    case SQUASH_BUFFER_FULL:
      return "Insufficient space in buffer";
    case SQUASH_BUFFER_EMPTY:
      return "Unable to read from buffer";
    case SQUASH_STATE:
      return "Performing the requested operation from the current state is not supported";
    case SQUASH_INVALID_OPERATION:
      return "The requested operation is not available";
    case SQUASH_NOT_FOUND:
      return "The requested codec could not be found";
    case SQUASH_INVALID_BUFFER:
      return "Invalid buffer";
    case SQUASH_IO:
      return "I/O error";
    case SQUASH_RANGE:
      return "Attempted to convert value outside of valid range";
    default:
      return "Unknown.";
  }
}

/**
 * @brief Emit an error
 *
 * This function simply returns the argument which was passed to it.
 * It exists only to make it easier to debug an error by setting a
 * breakpoint on this function.
 *
 * Note that only the initial point at which the error was generated
 * should call this function.  Do not call it when simply returning an
 * error that was generated by another function.
 *
 * @param status the error
 * @return the error
 */
SquashStatus
squash_error (SquashStatus status) {
  assert (status < SQUASH_OK);
  return status;
}

/**
 * @}
 */
