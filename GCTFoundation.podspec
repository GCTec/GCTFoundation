
Pod::Spec.new do |s|
  s.name         = "GCTFoundation"
  s.version      = "0.0.1"
  s.summary      = "Foundation库"
  s.description  = <<-DESC
  Foundation库，包含：
        GCTCategory：Foundation NS系列的方法扩展Category；
  GCTAutoPurgeCache：NSCache 的子类，在有系统警告时，会自动释放 Cache；
             CGTLog：Log 系列。用于打印台打印。包含等级过滤操作，自定义打印样式等。
                   DESC

  s.homepage     = "https://github.com/GCTec/GCTFoundation"
  s.license      = "MIT"
  s.author             = { "Later" => "lshxin89@126.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/GCTec/GCTFoundation.git", :tag => s.version }
  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
  s.frameworks = 'UIKit', 'Foundation', 'CoreText'
  s.requires_arc = true

  s.public_header_files = 'GCTFoundation/Classes/*.h'
  s.source_files = 'GCTFoundation/Classes/*.{h,m}'

  s.subspec 'GCTCategory' do |ss|
    ss.public_header_files = 'GCTFoundation/Classes/GCTCategory/**/*.h'
    ss.source_files = 'GCTFoundation/Classes/GCTCategory/**/*.{h,m}'
  end

  s.subspec 'GCTAutoPurgeCache' do |ss|
    ss.public_header_files = 'GCTFoundation/Classes/GCTAutoPurgeCache/*.h'
    ss.source_files = 'GCTFoundation/Classes/GCTAutoPurgeCache/*.{h,m}'
  end

  s.subspec 'CGTLog' do |ss|
    ss.public_header_files = 'GCTFoundation/Classes/GCTLog/*.h'
    ss.source_files = 'GCTFoundation/Classes/GCTLog/*.{h,m}'
  end
end
