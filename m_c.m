function b=m_c(m,a,s)
[p q]=size(a);x=max(max(a));
b=sparse(x*m,p*m);
for i=0:p-1
    a1=a(i+1,1);a2=a(i+1,2);a3=a(i+1,3);
    s1=s(2*i+1);s2=s(2*i+2);
    for j=0:m-1
        b((a1-1)*m+j+1,i*m+j+1)=1;
        if j+s1<m
            b((a2-1)*m+j+s1+1,i*m+j+1)=1;
        else
            b((a2-2)*m+j+s1+1,i*m+j+1)=1;
        end
        if j+s2<m
            b((a3-1)*m+j+s2+1,i*m+j+1)=1;
        else
            b((a3-2)*m+j+s2+1,i*m+j+1)=1;
        end
    end
end
