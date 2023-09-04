function y=alist(H,name);
%clc
%H=tanner(151,[1 8 64 59 19;32 105 85 76 4;118 38 2 16 128]);
%H=changcol(H,200);
 %  H=[0 1 0 1 1 0 1
  %  0 0 1 0 1 1 1];
% [ii,jj,sH] = find(H);

[m,n] = size(H);
y=(n-m)/n;
vr=zeros(1,m);
disp('vr is constitute');
for i=1:m
    vr(i)=nnz(H(i,:));
end
disp('vr is completed');
rowmax_wei=max(vr);
vc=zeros(1,n);
for i=1:n
    vc(i)=nnz(H(:,i));
end
colmax_wei=max(vc);
disp('vc is constitute');

% H = sparse(ii,jj,sH,m,n);
fid=fopen(name,'w+');
fprintf(fid,'%d %d\n',m,n);
fprintf(fid,'%d %d\n',rowmax_wei,colmax_wei);
for i=1:m
    fprintf(fid,'%d ',vr(i));
end
 fprintf(fid,'\n');
 for i=1:n
    fprintf(fid,'%d ',vc(i));
 end
 fprintf(fid,'\n');
for i=1:m
    [ii,jj] =find(H(i,:));
    [ss,tt]=size(jj);
%     tt
%     jj
    for j=1:tt
  fprintf(fid,'%d ',jj(j));  
    end
    for j=tt+1:rowmax_wei
  fprintf(fid,'%d ',0);  
    end
     fprintf(fid,'\n');
end
disp('loop 1 is end');
for i=1:n
    [ii,jj] = find(H(:,i));
    [ss,tt]=size(ii);
%     tt
%     jj
    for j=1:ss
  fprintf(fid,'%d ',ii(j));  
    end
    for j=ss+1:colmax_wei
  fprintf(fid,'%d ',0);  
    end
     fprintf(fid,'\n');
end
disp('loop 2 is end');
fclose(fid);