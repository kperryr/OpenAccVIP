# OpenAccVIP

This github displays mutliple Matrix Multiplication files with added OpenACC directives. Below is a list of each file and a discription. 

#Basic

This matrix multilication file has several OpenACC directives. This matrix is similar to most openacc martices.
1. acc data- pragma for data copy
2. acc kernels- intializer directive
3. acc loop thread tiles of 32x32
4. acc reduction clause

#acc_loop

This matrix multilication file has several OpenACC directives. 
1. acc data- pragma for data copy
2. acc kernels- intializer directive
3. acc loop - no clause
4. acc loop -no clause

#kernel_loops

This matrix multilication file has several OpenACC directives. 
1. acc data- pragma for data copy
2. acc kernels loop- intializer directive
3. acc loop thread tiles of 32x32 
4. acc reduction clause

#kernel_outerloop

This matrix multilication file one OpenACC directives. 
1. #pragma acc kernel- intializer compiler will choose what to parallelize



#nodatacopy

This matrix multilication file has several OpenACC directives. 
1. acc kernels loop- intializer directive
2. acc loop thread tiles of 16x16 
3. acc reduction clause

#outer_loop

This matrix multilication file has several OpenACC directives. 
1. acc data- pragma for data copy
2. acc kernels - intializer directive
4. acc reduction clause

#outer_loop

This matrix multilication file one OpenACC directives. 
1. acc parallel- pragma initalizer

#outer_loop

This matrix multilication file has several OpenACC directives. 
1. acc data- pragma for data copy
2. acc parallel - intializer directive
3. acc loop thread tiles of 16x16 
4. acc reduction clause

