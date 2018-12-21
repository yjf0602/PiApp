# 设定编译器
CC = gcc
GCC = g++

# use "pkg-config --cflags --libs opencv" cmd
LIB = -lbcm2835 -I/usr/local/include/opencv -I/usr/local/include -L/usr/local/lib -lopencv_calib3d -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_hal -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_shape -lopencv_stitching -lopencv_superres -lopencv_video -lopencv_videoio -lopencv_videostab -lopencv_adas -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_datasets -lopencv_face -lopencv_latentsvm -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_surface_matching -lopencv_text -lopencv_tracking -lopencv_xfeatures2d -lopencv_ximgproc -lopencv_xobjdetect -lopencv_xphoto -lstdc++

# 设定 .o 目录
BUILD_DIR = ./build

# 遍历子目录，排除 build
SUBDIRS=$(shell ls -l | grep ^d | awk '{if($$9 != "build") print $$9}')

# 记住当前工程的根目录路径
ROOT_DIR=$(shell pwd)

# 设置目标名字
TARGET = PiApp

# 获取当前目录下的cpp文件集，放在变量CUR_SOURCE中
CUR_SOURCE=${wildcard *.cpp}

# 将对应的c文件名转为o文件后放在下面的CUR_OBJS变量中
CUR_OBJS=${patsubst %.cpp, %.o, $(CUR_SOURCE)}

# 将以下变量导出到子shell中，本次相当于导出到子目录下的makefile中
export CC GCC BUILD_DIR ROOT_DIR LIB

# 注意这里的顺序，需要先执行 SUBDIRS 最后才能是 CUR_SOURCE
all:$(SUBDIRS) $(CUR_OBJS)
	$(CC) $(ROOT_DIR)/$(BUILD_DIR)/*.o -o $(TARGET) $(LIB)

# 跳转到对应的子目录，执行那里的 Makefile
$(SUBDIRS):ECHO
	-make -C $@

ECHO:
	@echo $(SUBDIRS)

# 执行最后的目标生成
$(CUR_OBJS):%.o:%.cpp
	$(GCC) -c $^ -o $@
	-cp $@ $(ROOT_DIR)/$(BUILD_DIR)/$@

clean:
	$(foreach N, $(SUBDIRS),make clean -C $(N);)
	-rm $(ROOT_DIR)/$(BUILD_DIR)/*.*
	-rm *.o
	-rm $(TARGET)

