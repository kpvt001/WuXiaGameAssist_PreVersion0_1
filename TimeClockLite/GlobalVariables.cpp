/* Copyright (c) 2016, %{Owner}%.
 * All rights reserved.

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the FreeBSD Project.
 */

#include "GlobalVariables.h"

GlobalVariables::GlobalVariables()
    : mTestCurrentTime(QTime::currentTime())
{

}

GlobalVariables::~GlobalVariables()
{

}

void GlobalVariables::InitTestMode()
{
}

GlobalVariables& GlobalVariables::Global()
{
    // C++11 to ensure thread safe.
    static GlobalVariables global;
    return global;
}

QTime& GlobalVariables::TestCurrentTime()
{
#if THREAD_SAFE
    mMutexTestCurrentTime.lock();
#endif

    return mTestCurrentTime;

#if THREAD_SAFE
    mMutexTestCurrentTime.unlock();
#endif
}

void GlobalVariables::SetTestCurrentTime(const QTime &time)
{
#if THREAD_SAFE
    mMutexTestCurrentTime.lock();
#endif

    mTestCurrentTime = time;

#if THREAD_SAFE
    mMutexTestCurrentTime.unlock();
#endif
}

GlobalVariables& GVar()
{
    return GlobalVariables::Global();
}
