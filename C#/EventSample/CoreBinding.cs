// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
//   CBGに似せたやつ
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

using System;
using System.ComponentModel;
using System.Collections.Generic;
using System.Collections.Concurrent;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;

namespace EventSample
{
    [EditorBrowsable(EditorBrowsableState.Never)]
    struct MemoryHandle
    {
        public IntPtr selfPtr;
        public MemoryHandle(IntPtr p)
        {
            this.selfPtr = p;
        }
    }

    public class CoreClass
    {
        #region unmanaged
        
        [EditorBrowsable(EditorBrowsableState.Never)]
        internal IntPtr selfPtr = IntPtr.Zero;
        
        [DllImport("CoreLib")]
        [EditorBrowsable(EditorBrowsableState.Never)]
        private static extern IntPtr cbg_CoreClass_Constructor_0();
        
        [DllImport("CoreLib")]
        [EditorBrowsable(EditorBrowsableState.Never)]
        private static extern void cbg_CoreClass_CallEvents(IntPtr selfPtr);
        
        [DllImport("CoreLib")]
        [EditorBrowsable(EditorBrowsableState.Never)]
        private static extern void cbg_CoreClass_AddEvent(IntPtr selfPtr, [MarshalAs(UnmanagedType.FunctionPtr)] Action callback);
        
        [DllImport("CoreLib")]
        [EditorBrowsable(EditorBrowsableState.Never)]
        private static extern void cbg_CoreClass_RemoveEvent(IntPtr selfPtr, [MarshalAs(UnmanagedType.FunctionPtr)] Action callback);
        
        [DllImport("CoreLib")]
        [EditorBrowsable(EditorBrowsableState.Never)]
        private static extern void cbg_CoreClass_Release(IntPtr selfPtr);

        #endregion

        [EditorBrowsable(EditorBrowsableState.Never)]
        internal CoreClass(MemoryHandle handle)
        {
            selfPtr = handle.selfPtr;
        }

        public event Action Callback
        {
            add
            {
                cbg_CoreClass_AddEvent(selfPtr, value);
            }
            remove
            {
                cbg_CoreClass_RemoveEvent(selfPtr, value);
            }
        }
        
        public CoreClass()
        {
            selfPtr = cbg_CoreClass_Constructor_0();
        }

        public void CallEvents()
        {
            cbg_CoreClass_CallEvents(selfPtr);
        }

        ~CoreClass()
        {
            lock (this) 
            {
                if (selfPtr != IntPtr.Zero)
                {
                    cbg_CoreClass_Release(selfPtr);
                    selfPtr = IntPtr.Zero;
                }
            }
        }
    }
}