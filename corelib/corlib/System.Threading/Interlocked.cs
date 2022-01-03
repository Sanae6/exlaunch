// Copyright (c) 2012 DotNetAnywhere
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#if !LOCALTEST

using System.Runtime.CompilerServices;
namespace System.Threading {
	public static class Interlocked {

		[MethodImpl(MethodImplOptions.InternalCall)]
		extern public static int CompareExchange(ref int loc, int value, int comparand);

		[MethodImpl(MethodImplOptions.InternalCall)]
		extern public static int Increment(ref int loc);

		[MethodImpl(MethodImplOptions.InternalCall)]
		extern public static int Decrement(ref int loc);

		[MethodImpl(MethodImplOptions.InternalCall)]
		extern public static int Add(ref int loc, int value);

		[MethodImpl(MethodImplOptions.InternalCall)]
		extern public static int Exchange(ref int loc, int value);

	}
}

#endif
