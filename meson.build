project('math','c')
cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)
executable('st','st.c', dependencies: m_dep)
